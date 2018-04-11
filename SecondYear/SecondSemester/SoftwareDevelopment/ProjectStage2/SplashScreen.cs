using UnityEngine;
using UnityEngine.SceneManagement;

public class SplashScreen : MonoBehaviour {

	public GameObject backgroundPanel;
	public Material[] materialArray;
    
	private void Awake() {

		int bgValue = PlayerPrefs.GetInt("bgValue", 0);

		switch (bgValue) {
		
			case 0:
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[0].mainTexture;
				break;
			case 1:
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[1].mainTexture;
				break;
			case 2:
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[2].mainTexture;
				break;
			case 3:
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[3].mainTexture;
				break;
		}

	}

	/*
	 * Description: Public function to be called by a UI Button during runtime, loads the game scene
	 */
	public void ShowMenu() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}

	/*
	 * Description: Public function to be called by a UI Button, exits the game completely
	 */
	public void QuitGame() {
		Application.Quit();
	}
}
