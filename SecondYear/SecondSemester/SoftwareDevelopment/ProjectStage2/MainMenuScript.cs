using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuScript : MonoBehaviour {
	
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

	public void LoadGame() {
		SceneManager.LoadScene("_Scene_0");
	}

	public void LoadGameLevels() {
		SceneManager.LoadScene("_GameLevel_Scene");
	}

	public void LoadConfigScene() {
		SceneManager.LoadScene("_Config_Scene");
	}

	public void LoadHistoryScene() {
		SceneManager.LoadScene("_Scene_History");
	}

	public void LoadSplashScreen() {
		SceneManager.LoadScene("_Scene_SplashScreen");
	}
}
