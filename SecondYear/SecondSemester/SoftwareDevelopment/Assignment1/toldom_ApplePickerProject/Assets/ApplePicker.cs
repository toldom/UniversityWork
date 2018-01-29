using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ApplePicker : MonoBehaviour {

	public GameObject basketPrefab;
	public GameObject treePrefab;
	public int numberOfBaskets = 3;
    public int basketsLost;
	public float basketBottomY = -14f;
	public float basketSpacingY = 2f;
	private int extraAppleTimer;

    public List<GameObject> basketList;

	private static int playerScore;
	public Text scoreText;

	private static int highscore;
	public Text highscoreText;

	private bool extraTreeFlag;
	private bool extraSpeedFlag;
	private bool extraAppleFlag;

	// Use this for initialization
	void Start () {

        basketsLost = 0;
        playerScore = 0;
		highscore = PlayerPrefs.GetInt ("highscore", highscore);

		extraAppleTimer = 10;

		extraTreeFlag = false;
		extraSpeedFlag = false;
		extraAppleFlag = false;

        basketList = new List<GameObject>();

		for (int i = 0; i < numberOfBaskets; i++) {
			GameObject tBasketGO = Instantiate (basketPrefab) as GameObject;
			Vector3 pos = Vector3.zero;
			pos.y = basketBottomY + (basketSpacingY * i);
			tBasketGO.transform.position = pos;
            basketList.Add(tBasketGO);
		}

        scoreText.text = "Score: " + playerScore.ToString();
		highscoreText.text = "High Score: " + highscore.ToString ();
		
		
	}
	
	// Update is called once per frame
	void Update () {

		if (playerScore > highscore) {
			highscore = playerScore;

			PlayerPrefs.SetInt ("highscore", highscore);
		}

		SetScoreText ();

        if (basketsLost >= 3) {
	        PlayerPrefs.SetInt("lastScore", playerScore);
            SceneManager.LoadScene("_Scene_GameOver");
        }

		if (playerScore == 10 && extraTreeFlag == false) {
			extraTreeFlag = true;
			MakeNewTree ();
			DifficultyUpMessage();
		}

		if (playerScore == 25 && extraSpeedFlag == false) {
			extraSpeedFlag = true;

			GameObject.Find ("AppleTree").SendMessage ("IncreaseDificulty");
			GameObject.Find("AppleTree(Clone)").SendMessage("IncreaseDificulty");
			DifficultyUpMessage();
		}

		if (playerScore == 40 && extraAppleFlag == false) {
			GameObject.Find("AppleTree").SendMessage("IncreaseDificulty2");
			GameObject.Find("AppleTree(Clone)").SendMessage("IncreaseDificulty2");			
			extraAppleFlag = true;
			DifficultyUpMessage();
		}

		if (Input.GetKeyDown(KeyCode.Escape)) {
			PauseGame();
		}
		
	}

	void SetScoreText() {
		scoreText.text = "Score: " + playerScore;
		highscoreText.text = "High Score: " + highscore;
	}

    void IncrementScoreValue() {
        playerScore++;
    }

    void AppleDestroyed() {

        GameObject[] tAppleArray = GameObject.FindGameObjectsWithTag("Apple");
        foreach (GameObject tGo in tAppleArray) {
            Destroy(tGo);
        }

        int basketIndex = basketList.Count - 1;

        GameObject tBasketGo = basketList[basketIndex];
        basketList.RemoveAt(basketIndex);
        Destroy(tBasketGo);

        basketsLost++;
    }

	void MakeNewTree() {
		Vector3 pos = new Vector3 (0, 14, 0);
		Instantiate (treePrefab, pos, Quaternion.identity);
	}

	void DifficultyUpMessage() {
		GameObject.Find("DifficultyUpText").SendMessage("Display");
	}

	public void PauseGame() {

		if (Time.timeScale == 1) {
			Time.timeScale = 0;
			GameObject.Find("PausedText").transform.SetAsLastSibling();
		} else {
			Time.timeScale = 1;
			GameObject.Find("PausedText").transform.SetAsFirstSibling();
		}
		
	}
	
}