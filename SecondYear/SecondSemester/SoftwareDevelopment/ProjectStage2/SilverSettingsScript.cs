using System;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SilverSettingsScript: MonoBehaviour {

	public Toggle[] enemyToggles;
	public InputField scoreThreshold, numberOfEnemies;
	public GameObject backgroundPanel;
	public Material[] materialArray;
	public Text errorText;
	
	private int[] toggleStatus = new int[5];
	private bool[] boolStatus = new bool[5];
	private int numberOfEnemiesInput, scoreThresholdInput;
    
	private void Awake() {
		
		toggleStatus[0] = PlayerPrefs.GetInt("e0Silver", 1);
		toggleStatus[1] = PlayerPrefs.GetInt("e1Silver", 1);
		toggleStatus[2] = PlayerPrefs.GetInt("e2Silver", 1);
		toggleStatus[3] = PlayerPrefs.GetInt("e3Silver", 1);
		toggleStatus[4] = PlayerPrefs.GetInt("e4Silver", 1);

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
		
		for (int i = 0; i < 5; i++) {
			if (toggleStatus[i] == 1) {
				enemyToggles[i].isOn = true;
				boolStatus[i] = true;
			}
			else {
				enemyToggles[i].isOn = false;
				boolStatus[i] = false;
			}
		}

	}
	
	private void Update() {
		if (numberOfEnemiesInput >= PlayerPrefs.GetInt("GoldEnemies", 0)) {
			errorText.GetComponent<Text>().enabled = true;
		} else {
			errorText.GetComponent<Text>().enabled = false;
		}
	}
	
	public void LoadLevelsScreen() {
		SceneManager.LoadScene("_GameLevel_Scene");
		PlayerPrefs.SetInt("SilverEnemies", numberOfEnemiesInput);
		PlayerPrefs.SetInt("GoldScoreThreshold", scoreThresholdInput);
		SetStatus();
	}
	
	public void toggleE0(bool status) {
		boolStatus[0] = status;
	}
	
	public void toggleE1(bool status) {
		boolStatus[1] = status;
	}
	
	public void toggleE2(bool status) {
		boolStatus[2] = status;
	}
	
	public void toggleE3(bool status) {
		boolStatus[3] = status;
	}
	
	public void toggleE4(bool status) {
		boolStatus[4] = status;
	}

	public void takeNumberOfEnemies(String input) {
		numberOfEnemiesInput = Int32.Parse(input);

	}

	public void takeScoreThreshold(String input) {
		scoreThresholdInput = Int32.Parse(input);
	}

	private void SetStatus() {
		if (boolStatus[0]) {
			PlayerPrefs.SetInt("e0Silver", 1);
		} else {
			PlayerPrefs.SetInt("e0Silver", 0);
		}
		
		if (boolStatus[1]) {
			PlayerPrefs.SetInt("e1Silver", 1);
		} else {
			PlayerPrefs.SetInt("e1Silver", 0);
		}
		
		if (boolStatus[2]) {
			PlayerPrefs.SetInt("e2Silver", 1);
		} else {
			PlayerPrefs.SetInt("e2Silver", 0);
		}
		
		if (boolStatus[3]) {
			PlayerPrefs.SetInt("e3Silver", 1);
		} else {
			PlayerPrefs.SetInt("e3Silver", 0);
		}
		
		if (boolStatus[4]) {
			PlayerPrefs.SetInt("e4Silver", 1);
		} else {
			PlayerPrefs.SetInt("e4Silver", 0);
		}
	}	
	
}
