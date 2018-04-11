/*												*
 * 		Software Development - 03-60-280		*
 * 		Assignment 2 - Rock Paper Scissors		*
 * 		Marcus Toldo - 104623006				*
 * 		Monday, February 12, 2018				*
 *												*/

using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MainScript : MonoBehaviour {

	public Text gamesPlayedText, playerWinsText, computerWinsText, countdownText, playerWinsLable, opponentWinsLable, drawLable;
	private int gamesPlayed, playerWins, computerWins, playerChoice, computerPick, countdownInt;
	private bool playerPicked, currentlyCountingDown;
	public GameObject rock1, paper1, scisors1, rock2, paper2, scissors2, clickBlocker;
	private GameObject playerObject;
	public Button resetButton;

	// Use this for initialization
	private void Start () {

		//Initializing int variables
		gamesPlayed = 0;
		playerWins = 0;
		computerWins = 0;
		playerChoice = -1;
		countdownInt = 3;
		
		//Initializing bool variables
		playerPicked = false;
        currentlyCountingDown = false;
		
		//Setting game text to inactive
		countdownText.gameObject.SetActive(false);
		playerWinsLable.gameObject.SetActive(false);
		opponentWinsLable.gameObject.SetActive(false);
		drawLable.gameObject.SetActive(false);
		resetButton.gameObject.SetActive(false);
		clickBlocker.SetActive(false);

		//Clearing PlayerPrefs
		PlayerPrefs.DeleteAll();

	}
	
	// Update is called once per frame
	private void Update () {
		
		//Refreshes text content every frame
		SetTexts();
		
		//Sets the current relative scores to PlayerPrefs, to be accesed by a different script
		PlayerPrefs.SetInt("youScore", playerWins);
		PlayerPrefs.SetInt("compScore", computerWins);

		//Once the signal has been given that the player has made an object selection, the main game loop will be kicked
		//off here
		if (playerPicked) {
			
			playerPicked = false;
			
			//Activates the object that prevents the player from clicking multiple objects while the main game loop runs
			clickBlocker.SetActive(true);
			
			GameLoop();

		}
		
	}

	//This function is set (in Unity editor) to update once every second
	private void FixedUpdate() {
		
		//This code handles part of the countdown sequence, specifically deincrementing the coundown int, as this 
		//function is executed once every second
		if (currentlyCountingDown) {
			countdownInt -= 1;

			if (countdownInt == 0) {
				currentlyCountingDown = false;
				countdownInt = 3;
				countdownText.gameObject.SetActive(false);
			}
		}
		
	}

	/*
	 * Objective: Begins a round of rps, where it renders the players choice (hidden) and after a 3 second countdown,
	 * 			  will then display the opponents object, and announce the winner. In order to get the countdown to
	 * 			  work as intended, the use of a coroutine was required. In this function, the players object is created
	 * 			  and hidden, the countdown is started, and then the coroutine begins for the rest of the game loop
	 */
	private void GameLoop() {
		
		RenderPlayerObject(playerChoice);
		HideObject(playerChoice);
			
		TriggerCountdown();

		StartCoroutine(GameLoopCoroutine());
	}

	/*
	 * Objective: This is the second part of the game loop, that handles everything that will occur after the 3 second
	 * 			  countdown. This part of the loop handles the computers turn, un-hiding the players object, evaluating
	 * 			  a winner and then displaying the corresponding lables on screen. 
	 */
	private IEnumerator GameLoopCoroutine() {
		
		yield return new WaitForSeconds(3);
		
		ComputersTurn();
		ShowObject(playerChoice);
		resetButton.gameObject.SetActive(true);

		//This conditional evaluates the winner of the match, if it ended with the player or computer winning, or in a
		//draw. It checks for a draw first, if not a draw, then it evaluates who won based on their relative selections.
		if (playerChoice == computerPick) {
			print("Its a draw!");
			drawLable.gameObject.SetActive(true);
			gamesPlayed++;
		} else if (playerChoice == 1) {
			if (computerPick == 2) {
				print("Computer wins!");
				opponentWinsLable.gameObject.SetActive(true);
				computerWins++;
				gamesPlayed++;
			} else if (computerPick == 3) {
				print("Player wins!");
				playerWinsLable.gameObject.SetActive(true);
				playerWins++;
				gamesPlayed++;
			}
		} else if (playerChoice == 2) {
			if (computerPick == 1) {
				print("Player wins!");
				playerWinsLable.gameObject.SetActive(true);
				playerWins++;
				gamesPlayed++;
			} else if (computerPick == 3) {
				print("Computer wins!");
				opponentWinsLable.gameObject.SetActive(true);
				computerWins++;
				gamesPlayed++;
			}
		} else {
			if (computerPick == 1) {
				print("Computer wins!");
				opponentWinsLable.gameObject.SetActive(true);
				computerWins++;
				gamesPlayed++;
			} else if (computerPick == 2) {
				print("Player wins!");
				playerWinsLable.gameObject.SetActive(true);
				playerWins++;
				gamesPlayed++;
			}
 		}

	}

	/*
	 * Objective: Sets the default values for our text variables, that represent the score labels in the main game Unity scene
	 * Input: No input
	 * Output: No output; void function
	 */
	private void SetTexts() {
		gamesPlayedText.text = "Games Played: " + gamesPlayed;
		playerWinsText.text = "Wins: " + playerWins;
		computerWinsText.text = "Wins: " + computerWins;
		countdownText.text = countdownInt.ToString();
	}
	
	/*
	 * Objective: Instanciates the players choice of rps
	 * Input: Recieves the players choice of rps represented as an Int value
	 * Output: No output; void function
	 */
	private void RenderPlayerObject(int playerChoice) {
		switch (playerChoice) {
			case 1:
				Instantiate(rock1);
				break;
			case 2:
				Instantiate(paper1);
				break;
			case 3:
				Instantiate(scisors1);
				break;
			default:
				return;
		}
	}
	
	/*
	 * Objective: Depending on the player choosing rps, sets the relative value for z attribute to 0, to make the object
	 * 			  apear as a silhouette
	 * Input: Recieves the players choise of rps, represented as an Int. Information is processed through a switch statement
	 * Output: No output; void function
	 */
	private void HideObject(int playerChoice) {
		
		playerObject = GameObject.FindWithTag("Player1Objects");
		
		switch (playerChoice) {
		
			case 1:
				playerObject.transform.localScale -= new Vector3(0, 0, 0.6F);
				break;

			case 2:
				playerObject.transform.localScale -= new Vector3(0, 0, 0.5F);
				break;
				
			case 3:
				playerObject.transform.localScale -= new Vector3(0, 0.3F, 0);
				break;
				
			default:
				return;
		}
	}

	/*
	 * Objective: This function will show the player object by resetting its z scale to the appropriate level. This
	 * 			  function undoes the changes of the 'HideObject' function.
	 */
	private void ShowObject(int playerChoice) {
		
		switch (playerChoice) {
		
			case 1:
				playerObject.transform.localScale += new Vector3(0, 0, 0.6F);
				break;

			case 2:
				playerObject.transform.localScale -= new Vector3(0, 0, 0.5f);
				break;
				
			case 3:
				playerObject.transform.localScale += new Vector3(0, 0.3F, 0);
				break;
				
			default:
				return;
		}
	}

	/*
	 * Objective: This function will trigger the countdown sequence, activates the countdown text and begins the
	 * 			  deincrementing in the 'FixedUpdate' function.
	 */
	private void TriggerCountdown() {
		countdownText.gameObject.active = true;
		currentlyCountingDown = true;
	}

	/*
	 * Objective: Handels the computers "turn" by randomly choosing rps
	 * Inpit: No input
	 * Output: No output; void function
	 */
	private void ComputersTurn() {

		//Randomy pick between 1 - 3
		computerPick = Random.Range(1, 4);

		if (computerPick == 1) {
			Instantiate(rock2);
		} else if (computerPick == 2) {
			Instantiate(paper2);
		} else if (computerPick == 3) {
			Instantiate(scissors2);
		}

		
	}

	/*
	 * Objective: This function resets the GameFiew scene to its original state. Hides all appropriate UI elements that
	 * 			  should be hidden, removes all rendered rps objects for both the player and computer, and deactivates
	 * 			  the click blocker so that players can click the rps choice buttons again. 
	 */
	public void ResetScene() {

		//If there have been 10 rounds of the game, the game is over, and the 'game over' scene is loaded, where results
		//will be displayed to the user.
		if (gamesPlayed == 10) {
			
			SceneManager.LoadScene("_Scene_GameOverRPS");
		}
		
		GameObject opponentObject = GameObject.FindWithTag("Player2Objects");
		
		Destroy(playerObject);
		Destroy(opponentObject);

		playerWinsLable.gameObject.SetActive(false);
		opponentWinsLable.gameObject.SetActive(false);
		resetButton.gameObject.SetActive(false);
		drawLable.gameObject.SetActive(false);
		clickBlocker.SetActive(false);
	}
	
	/*
	 * The following three functions, 'RockClicked', 'PaperClicked' and 'ScissorsClicked' are all public funtions that
	 * exist to be signaled from the rock, paper and scissors scripts respectively. They set off the 'playerPicked' flag
	 * and indicate what choice the player made
	 */
	public void RockClicked() {
		playerPicked = true;
		playerChoice = 1;
	}

	public void PaperClicked() {
		playerPicked = true;
		playerChoice = 2;
	}

	public void ScissorsClicked() {
		playerPicked = true;
		playerChoice = 3;
	}
}
