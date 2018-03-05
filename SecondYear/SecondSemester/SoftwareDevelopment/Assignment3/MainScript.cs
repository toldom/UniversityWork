using System;
using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Random = UnityEngine.Random;

public class MainScript : MonoBehaviour {
	
	//Creating the varibales that will hold the prefabs for 10 unique cards
	[Header("Card Prefabs: Set in Inspector")]
	public GameObject[] CardPrefabArray;

	public Text scoreText, pairsText, timeText;
	public AudioClip cardMatchSound, noMatchSound; 
	
	//Private Variables
	private int score = 1000, pairsFound;
	private int difficulty, arraySize, firstNL, secondNL, thirdNL, xReset, xStart, scoreThreshold;
	private GameObject[] randomlyPlacedCards;
	private ArrayList instanciatedCards = new ArrayList();
	private GameObject flippedCard1, flippedCard2;
	private bool[] OneCardFlag = {false, false, false, false, false, false, false, false, false, false};
	private bool[] TwoCardFlag = {false, false, false, false, false, false, false, false, false, false};
	private bool cardFlip1, cardFlip2;
	private AudioSource audio;

	private void Awake() {
		
		//Setting difficulty from PlayerPrefs
		difficulty = PlayerPrefs.GetInt("difficulty", 3);
		
		//Initializing varaibles
		pairsFound = 0;
		cardFlip1 = false;
		cardFlip2 = false;
		
		//Switch case to set dificulty customizations
		switch (difficulty) {
			case 1:
				arraySize = 12;
				firstNL = 2;
				secondNL = 5;
				thirdNL = 8;
				xReset = 12;
				xStart = -6;
				scoreThreshold = 6;
				break;
			case 2:
				arraySize = 16;
				firstNL = 3;
				secondNL = 7;
				thirdNL = 11;
				xReset = 15;
				xStart = -9;
				scoreThreshold = 8;
				break;
			case 3:
				arraySize = 20;
				firstNL = 4;
				secondNL = 9;
				thirdNL = 14;
				xReset = 18;
				xStart = -12;
				scoreThreshold = 10;
				break;
			default:
				arraySize = 20;
				break;
		}

		audio = GetComponent<AudioSource>();
		
		RandomlySetCards(arraySize);
	}

	void Start () {
		
		SetTexts();
		DisplayCards();
		
	}

	void Update() {
		
		//Checks to see if two cards have been clicked
		if (cardFlip2) {
			cardFlip2 = false;
            cardFlip1 = false;
			FindFlippedCards();
		}
		
		SetTexts();

		//Checks to see if the player has found all pairs
		if (pairsFound == scoreThreshold) {
			PlayerPrefs.SetInt("didWin", 1);
			PlayerPrefs.SetFloat("LastTime", Convert.ToInt64(Math.Ceiling(Time.timeSinceLevelLoad)));
			SceneManager.LoadScene("_EndScene");
		}
		
		//Checks to see if score is zero, determining if player looses or not
		if (score <= 0) {
			PlayerPrefs.SetInt("didWin", 0);
			PlayerPrefs.SetFloat("LastTime", Convert.ToInt64(Math.Ceiling(Time.timeSinceLevelLoad)));
			SceneManager.LoadScene("_EndScene");
		}
	}

	/*
	 * Objective: Function will set the corresponding text boxes in the UI layer of Unity to show the correct information
	 */
	void SetTexts() {
		scoreText.text = "Score: " + score;
		pairsText.text = "Pairs Found: " + pairsFound;
		timeText.text = "Elapsed Time: " + Math.Ceiling(Time.timeSinceLevelLoad);
	}

	/*
	 * Objective: Function will populate an array (size based on difficulty) with ONLY TWO of each card that is avaliable to that difficulty.
	 * 			  Difficulty is set in PlayerPrefs (default 3, 'hardest'), array size 12, 16, 20 respectively for difficulty levels 1 - 3
	 * 			  The number of cards used from our collection of card prefabs are arraySize/2
	 * Input: 	  Recieves 'arraySize' as an input paramater, and defines the array within accordingly 
	 */
	void RandomlySetCards(int arraySize) {

		//Declaring local variables
		int rand;
		
		//Initializing the GameObject array
		randomlyPlacedCards = new GameObject[arraySize];

		//Loop to populate array with card objects
		for (int i = 0; i < arraySize; i++) {
			
			rand = Random.Range(0, arraySize/2);
			
			//If a card has NOT been used twice already...
			if (!TwoCardFlag[rand]) {
				
				randomlyPlacedCards[i] = CardPrefabArray[rand];
				
				//Flags if a card has been used either once or twice...
				if (OneCardFlag[rand] == false) {
					OneCardFlag[rand] = true;
				} else {
					TwoCardFlag[rand] = true;
				}
			} else {
				//De-increment loop if a card prefab gets selected more than twice
				i--;
			}
		}
	}

	/*
	 * Objective: Will instanciate the cards that were previously randomly placed in the 'randomlyPlacedCards' array
	 * 			  to their appropriate positions on the game screen. 
	 */
	private void DisplayCards() {

		int posX = xStart, posY = 6;
		GameObject cardTemp;

		for (var i = 0; i < randomlyPlacedCards.Length; i++) {
			cardTemp = randomlyPlacedCards[i];
			cardTemp = Instantiate(cardTemp);
			
			cardTemp.transform.position = new Vector3(posX, posY);

			if (i == firstNL || i == secondNL || i == thirdNL) {
				posY -= 4;
			}

			posX += 6;

			if (posX == xReset) {
				posX = xStart;
			}

			instanciatedCards.Add(cardTemp);
		}

	}

	
	/*
	 * Objective: This function will discover which of the two cards on the game screen have been flipped to show the
	 * 			  card face, by accessing the "isFlipped" boolean varaibel that each card has in its script. 
	 */
	private void FindFlippedCards() {

		Cursor.visible = false;
		Cursor.lockState = CursorLockMode.Locked;

		foreach (GameObject obj in instanciatedCards) {
			CardScript cs = obj.GetComponent<CardScript>();

			if (cs.isFlipped) {
				if (flippedCard1 == null) {
					flippedCard1 = obj;
				} else {
					flippedCard2 = obj;
				}
			}
		}
		
		EvaluateFlippedCards();
	}

	/*
	 * Objective: Compare the two cards that were flipped over and determine if they match or not
	 */
	private void EvaluateFlippedCards() {

		if (flippedCard1.name == flippedCard2.name) {
			pairsFound++;

			audio.clip = cardMatchSound;
			audio.PlayOneShot(cardMatchSound);

			GameObject tempObj1 = null, tempObj2 = null;
			
			foreach (GameObject obj in instanciatedCards) {

				if (obj.name == flippedCard1.name) {
					if (tempObj1 == null) {
						tempObj1 = obj;
					} else {
						tempObj2 = obj;
					}
				}
			}	
			
			//Remove the matched cards from the list of cards and destroy the game objects
			instanciatedCards.Remove(tempObj1);
			instanciatedCards.Remove(tempObj2);
			Destroy(flippedCard1);
			Destroy(flippedCard2);

			flippedCard1 = null;
			flippedCard2 = null;
			
			//Show the mouse cursor again
			Cursor.visible = true;
			Cursor.lockState = CursorLockMode.None;

		} else {
			
			//Decrease score by 40
			score -= 40;

			audio.PlayOneShot(noMatchSound);
			
			flippedCard1.SendMessage("ResetFlip");
			flippedCard2.SendMessage("ResetFlip");

			flippedCard1 = null;
			flippedCard2 = null;
			
		}
	}

	/*
	 * Objective: Public function that is triggered by CardScript that sets the cardFlip booleans to true upon cards
	 * 			  being clicked
	 */
	public void CardFlipTrigger() {

		if (!cardFlip1) {
			cardFlip1 = true;
		} else {
			cardFlip2 = true;
		}
		
	}
}
