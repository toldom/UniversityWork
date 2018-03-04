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

	private void SetTexts() {

		timeText.text = "Elapsed Time: " + PlayerPrefs.GetFloat("LastTime", -1);
	}

	public void LoadMainMenu() {
		SceneManager.LoadScene("_MainMenu");
	}

	public void LoadGame() {
		SceneManager.LoadScene("_Scene_0");
	}
}
