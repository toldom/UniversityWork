using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class EndScript : MonoBehaviour {

	public Text timeText, winText, loseText, winTextChild, loseTextChild;
	public AudioClip winSound, loseSound;

	private AudioSource audio;

	// Use this for initialization
	void Start () {
		
		Cursor.visible = true;
		Cursor.lockState = CursorLockMode.None;

		audio = GetComponent<AudioSource>();
		
		SetTexts();
		
		//Checks weather or not the player won the game or not, performs appropriate actions
		if (PlayerPrefs.GetInt("didWin", 0) == 1) {
			audio.PlayOneShot(winSound);
			loseText.enabled = false;
			loseTextChild.enabled = false;
		} else {
			audio.PlayOneShot(loseSound);
			winText.enabled = false;
			winTextChild.enabled = false;
		}
	}

	/*
	 * Objective: Sets the value of the text objects to be displaying the correct value
	 */
	private void SetTexts() {

		timeText.text = "Elapsed Time: " + PlayerPrefs.GetFloat("LastTime", -1);
	}

	/*
	 * Objective: Public function to be called by a button click, loads the main menu
	 */
	public void LoadMainMenu() {
		SceneManager.LoadScene("_MainMenu");
	}

	/*
	 * Objective: Public function to be called by a button click, loads the game scene
	 */
	public void LoadGame() {
		SceneManager.LoadScene("_Scene_0");
	}
}
