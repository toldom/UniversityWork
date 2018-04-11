/*												*
 * 		Software Development - 03-60-280		*
 * 		Assignment 2 - Rock Paper Scissors		*
 * 		Marcus Toldo - 104623006				*
 * 		Monday, February 12, 2018				*
 *												*/

using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameOverScript : MonoBehaviour {

	public Text youWinText, youLostText, itsADrawText, playerScoreText, opponentScoreText;

	// Use this for initialization
	void Start () {

		SetTexts();

		//This conditional statement displays "win", "lose" or "draw" according the the relation between the users and
		//computers final scores. By default in the scene, all three cases are shown. This code will hide the two that
		//are not accurate to the outcome of the game. 
		if (PlayerPrefs.GetInt("youScore") > PlayerPrefs.GetInt("compScore")) {
			youLostText.gameObject.SetActive(false);
			itsADrawText.gameObject.SetActive(false);
		} else if (PlayerPrefs.GetInt("compScore")> PlayerPrefs.GetInt("youScore")) {
			youWinText.gameObject.SetActive(false);
			itsADrawText.gameObject.SetActive(false);
		} else {
			youWinText.gameObject.SetActive(false);
			youLostText.gameObject.SetActive(false);
		}

	}

	/*
	 * Objective: This function sets the text variables to display both the players final score and the computers final
	 * 			  score to the user at the conclusion of the game. 
	 */
	private void SetTexts() {

		playerScoreText.text = "Your Score: " + PlayerPrefs.GetInt("youScore");
		opponentScoreText.text = "Opponents Score: " + PlayerPrefs.GetInt("compScore");
	}

	/*
	 * Objective: This is a public funciton that is called upon pressing the menu button, that will return the user to
	 * 			  the games main menu
	 */
	public void ReturnToMainMenu() {
		SceneManager.LoadScene("_Scene_MainMenuRPS");
	}
	
}
