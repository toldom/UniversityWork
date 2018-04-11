using UnityEngine;
using UnityEngine.SceneManagement;

public class LevelSceneScript : MonoBehaviour {
	
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

	public void LoadGoldScene() {
		SceneManager.LoadScene("_Level_Gold");
	}
	
	public void LoadSilverScene() {
		SceneManager.LoadScene("_Level_Silver");
	}
	
	public void LoadBronzeScene() {
		SceneManager.LoadScene("_Level_Bronze");
	}
	
	public void LoadMainMenu() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}
}
