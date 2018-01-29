using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainUIFunctions : MonoBehaviour {

	public void StartGame() {
		SceneManager.LoadScene("_Scene_0");
	}

	public void ResetScore() {
		PlayerPrefs.DeleteKey("highscore");
	}

	public void ShowInfo() {
		SceneManager.LoadScene("_Scene_InfoUI");
	}
	
}
