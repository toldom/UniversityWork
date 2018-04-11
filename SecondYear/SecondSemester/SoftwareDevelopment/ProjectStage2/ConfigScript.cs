using UnityEngine;
using UnityEngine.SceneManagement;

public class ConfigScript : MonoBehaviour {
	
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

	public void LoadEnemiesSettings() {
		SceneManager.LoadScene("_Settings_Enemies");
	}

	public void LoadAudioSettings() {
		SceneManager.LoadScene("_Settings_Audio");
	}

	public void LoadBackgroundSettings() {
		SceneManager.LoadScene("_Settings_Background");
	}

	public void LoadMainMenu() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}

}
