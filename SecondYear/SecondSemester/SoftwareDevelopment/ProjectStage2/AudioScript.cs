using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class AudioScript : MonoBehaviour {
	
	public Slider musicVolume, winVolume, blasterVolume, destructionVolume; 
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

	public void LoadConfigMenu() {
		SceneManager.LoadScene("_Config_Scene");
	}

}
