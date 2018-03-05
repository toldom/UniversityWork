using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuScript : MonoBehaviour {

	/*
	 * Objective: Public function to be called by a button click, loads the game menu
	 */
	public void LoadGame() {
		SceneManager.LoadScene("_Scene_0");
	}

	/*
	 * Objective: Public function to be called by a button click, loads the settings menu
	 */
	public void LoadSettings() {
		SceneManager.LoadScene("_Settings");
	}

	/*
	 * Objective: Public function to be called by a button click, exits the game
	 */
	public void ExitGame() {
		Application.Quit();
	}

}
