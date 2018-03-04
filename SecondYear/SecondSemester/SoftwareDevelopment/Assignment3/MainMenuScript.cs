using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuScript : MonoBehaviour {

	public void LoadGame() {
		SceneManager.LoadScene("_Scene_0");
	}

	public void LoadSettings() {
		SceneManager.LoadScene("_Settings");
	}

	public void ExitGame() {
		Application.Quit();
	}

}
