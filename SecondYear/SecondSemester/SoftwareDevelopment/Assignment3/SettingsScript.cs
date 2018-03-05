using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SettingsScript : MonoBehaviour {

	public Text vryEZText, EZText, normalText;

	private void Awake() {
		DisableTexts();
	}

	/*
	 * Objective: Public function to be called upon a UI Button click, loads main menu
	 */
	public void LoadMainMenu() {
		SceneManager.LoadScene("_MainMenu");
	}

	/*
	 * Objective: Sets the game difficulty in PlayerPrefs to 1 for "very easy", displays appropriate text
	 */
	public void SetVeryEasy() {
		PlayerPrefs.SetInt("difficulty", 1);
		DisableTexts();
		vryEZText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	/*
	 * Objective: Sets the game difficulty in PlayerPrefs to 2 for "easy", displays appropriate text
	 */
	public void SetEasy() {
		PlayerPrefs.SetInt("difficulty", 2);
		DisableTexts();
		EZText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	/*
	 * Objective: Sets the game difficulty in PlayerPrefs to 3 for "normal", displays appropriate text
	 */
	public void SetNormal() {
		PlayerPrefs.SetInt("difficulty", 3);
		DisableTexts();
		normalText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	/*
	 * Objective: Calls the DisableTexts funtion after a 2 second delay, this function is called after a text item is
	 * 			  displayed, so the text boxes are only displayed for a short amount of time
	 */
	private IEnumerator TextDisplayTemp() {
		
		yield return new WaitForSeconds(2);

		DisableTexts();
	}

	/*
	 * Objective: Disables all text items
	 */
	private void DisableTexts() {
		vryEZText.enabled = false;
		EZText.enabled = false;
		normalText.enabled = false;
	}
}
