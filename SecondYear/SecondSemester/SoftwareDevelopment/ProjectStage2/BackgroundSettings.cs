using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class BackgroundSettings : MonoBehaviour {

	[Header("Set in Unity Inspector")] 
	public Dropdown backgroundSelector;
	public Image backgroundPreview;
	public Sprite[] imageArray;
	public Material[] materialArray = {};
	public GameObject backgroundPanel;
	public Slider XSlider, YSlider;

	private void Awake() {

		int bgValue = PlayerPrefs.GetInt("bgValue", 0);

		switch (bgValue) {
		
			case 0:
				backgroundPreview.sprite = imageArray[0];
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[0].mainTexture;
				break;
			case 1:
				backgroundPreview.sprite = imageArray[1];
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[1].mainTexture;
				break;
			case 2:
				backgroundPreview.sprite = imageArray[2];
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[2].mainTexture;
				break;
			case 3:
				backgroundPreview.sprite = imageArray[3];
				backgroundPanel.GetComponent<Renderer>().material.mainTexture = materialArray[3].mainTexture;
				break;
		}

	}

	/*
	 * Objective: Handles returning to the previous scene, and saving the choice for background
	 */
	public void LoadConfigMenu() {

		switch (backgroundPreview.sprite.name) {
		
			case "blackbg":
				PlayerPrefs.SetInt("bgValue", 0);
				break;
			case "spacebg1":
				PlayerPrefs.SetInt("bgValue", 1);
				break;
			case "spacebg2":
				PlayerPrefs.SetInt("bgValue", 2);
				break;
			case "spacebg3":
				PlayerPrefs.SetInt("bgValue", 3);
				break;
		}
		
		SceneManager.LoadScene("_Config_Scene");
	}

	/*
	 * Objective: This function handles the use of the dropdown menu, and setting the image preview
	 */
	public void BackgroundSelect(int pick) {
		
		switch (pick) {
			case 0:
				backgroundPreview.sprite = imageArray[0];
				break;
			case 1:
				backgroundPreview.sprite = imageArray[1];
				break;
			case 2:
				backgroundPreview.sprite = imageArray[2];
				break;
			case 3:
				backgroundPreview.sprite = imageArray[3];
				break;
		}
	}
	
}
