using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameOverUIFunctions : MonoBehaviour {

	public Text scoreText;
	public Text highScoreText;
	private int scoreEarned;
	private int currentHighScore;

	private void Start() {
		SetText();
		currentHighScore = PlayerPrefs.GetInt("highscore");
		DisplayHighScoreText();
	}

	public void Return() {
		SceneManager.LoadScene("_Scene_MainUI");
	}

	public void PlayAgain() {
		SceneManager.LoadScene("_Scene_0");
	}

	void SetText() {
		scoreEarned = PlayerPrefs.GetInt("lastScore");
		scoreText.text = "You finished with a score of " + scoreEarned;
	}

	void DisplayHighScoreText() {
		if (scoreEarned == currentHighScore) {
			highScoreText.transform.SetAsLastSibling();
		}
	}
	
}
