using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SettingsScript : MonoBehaviour {

	public Text vryEZText, EZText, normalText;

	private void Awake() {
		DisableTexts();
	}

	public void LoadMainMenu() {
		SceneManager.LoadScene("_MainMenu");
	}

	public void SetVeryEasy() {
		PlayerPrefs.SetInt("difficulty", 1);
		DisableTexts();
		vryEZText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	public void SetEasy() {
		PlayerPrefs.SetInt("difficulty", 2);
		DisableTexts();
		EZText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	public void SetNormal() {
		PlayerPrefs.SetInt("difficulty", 3);
		DisableTexts();
		normalText.enabled = true;
		StartCoroutine(TextDisplayTemp());
	}

	private IEnumerator TextDisplayTemp() {
		
		yield return new WaitForSeconds(2);

		DisableTexts();
	}

	private void DisableTexts() {
		vryEZText.enabled = false;
		EZText.enabled = false;
		normalText.enabled = false;
	}
}
