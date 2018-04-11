using System;
using System.Security.Cryptography;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class EnemiesSettings : MonoBehaviour {

	[Header("Set in Unity Inspector")]
	public Dropdown[] scoreDropdown;
	public Dropdown[] colourDropdown;
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
		SetDropdownMenus();

	}

	public void LoadConfigMenu() {
		SceneManager.LoadScene("_Config_Scene");
	}

	public void Enemy0ScoreSetter(int pick) {
		
		switch (pick) {
				case 0:
					PlayerPrefs.SetInt("e0Score", 5);
					break;
				case 1:
					PlayerPrefs.SetInt("e0Score", 10);
					break;
				case 2:
					PlayerPrefs.SetInt("e0Score", 15);
					break;
		}
	}
	
	public void Enemy1ScoreSetter(int pick) {

		switch (pick) {
			case 0:
				PlayerPrefs.SetInt("e1Score", 10);
				break;
			case 1:
				PlayerPrefs.SetInt("e1Score", 20);
				break;
			case 2:
				PlayerPrefs.SetInt("e1Score", 30);
				break;
		}
	}
	
	public void Enemy2ScoreSetter(int pick) {

		switch (pick) {
			case 0:
				PlayerPrefs.SetInt("e2Score", 15);
				break;
			case 1:
				PlayerPrefs.SetInt("e2Score", 30);
				break;
			case 2:
				PlayerPrefs.SetInt("e2Score", 45);
				break;
		}
	}
	
	public void Enemy3ScoreSetter(int pick) {

		switch (pick) {
			case 0:
				PlayerPrefs.SetInt("e3Score", 20);
				break;
			case 1:
				PlayerPrefs.SetInt("e3Score", 40);
				break;
			case 2:
				PlayerPrefs.SetInt("e3Score", 60);
				break;
		}
	}
	
	public void Enemy4ScoreSetter(int pick) {

		switch (pick) {
			case 0:
				PlayerPrefs.SetInt("e4Score", 50);
				break;
			case 1:
				PlayerPrefs.SetInt("e4Score", 75);
				break;
			case 2:
				PlayerPrefs.SetInt("e4Score", 100);
				break;
		}
	}
	
	public void Enemy0ColourSetter(int pick) {
		switch (pick) {
		
			case 0:
				PlayerPrefs.SetString("e0Col", "def");
				break;
			case 1:
				PlayerPrefs.SetString("e0Col", "red");
				break;
			case 2:
				PlayerPrefs.SetString("e0Col", "grn");
				break;
			case 3:
				PlayerPrefs.SetString("e0Col", "blu");
				break;
		}
	}
	
	public void Enemy1ColourSetter(int pick) {
		switch (pick) {
		
			case 0:
				PlayerPrefs.SetString("e1Col", "def");
				break;
			case 1:
				PlayerPrefs.SetString("e1Col", "red");
				break;
			case 2:
				PlayerPrefs.SetString("e1Col", "grn");
				break;
			case 3:
				PlayerPrefs.SetString("e1Col", "blu");
				break;
		}
	}
	
	public void Enemy2ColourSetter(int pick) {
		switch (pick) {
		
			case 0:
				PlayerPrefs.SetString("e2Col", "def");
				break;
			case 1:
				PlayerPrefs.SetString("e2Col", "red");
				break;
			case 2:
				PlayerPrefs.SetString("e2Col", "grn");
				break;
			case 3:
				PlayerPrefs.SetString("e2Col", "blu");
				break;
		}
	}

	public void Enemy3ColourSetter(int pick) {
		switch (pick) {
		
			case 0:
				PlayerPrefs.SetString("e3Col", "def");
				break;
			case 1:
				PlayerPrefs.SetString("e3Col", "red");
				break;
			case 2:
				PlayerPrefs.SetString("e3Col", "grn");
				break;
			case 3:
				PlayerPrefs.SetString("e3Col", "blu");
				break;
		}
	}
	
	public void Enemy4ColourSetter(int pick) {
		switch (pick) {
		
			case 0:
				PlayerPrefs.SetString("e4Col", "def");
				break;
			case 1:
				PlayerPrefs.SetString("e4Col", "red");
				break;
			case 2:
				PlayerPrefs.SetString("e4Col", "grn");
				break;
			case 3:
				PlayerPrefs.SetString("e4Col", "blu");
				break;
		}
	}

	private void SetDropdownMenus() {
		int e0S = PlayerPrefs.GetInt("e0Score", 5);
		int e1S = PlayerPrefs.GetInt("e1Score", 10);
		int e2S = PlayerPrefs.GetInt("e2Score", 15);
		int e3S = PlayerPrefs.GetInt("e3Score", 20);
		int e4S = PlayerPrefs.GetInt("e4Score", 50);

		int s0v, s1v, s2v, s3v, s4v;

		int[] setScores = {e0S, e1S, e2S, e3S, e4S};

		switch (e0S) {
			case 5:
				s0v = 0;
				break;
			case 10:
				s0v = 1;
				break;
			case 15:
				s0v = 2;
				break;	
			default:
				s0v = 0;
				break;
		}

		switch (e1S) {
			case 10:
				s1v = 0;
				break;
			case 20:
				s1v = 1;
				break;
			case 30:
				s1v = 2;
				break;	
			default:
				s1v = 0;
				break;
		}
		
		switch (e2S) {
			case 15:
				s2v = 0;
				break;
			case 30:
				s2v = 1;
				break;
			case 45:
				s2v = 2;
				break;
			default:
				s2v = 0;
				break;
		}
		
		switch (e3S) {
			case 20:
				s3v = 0;
				break;
			case 40:
				s3v = 1;
				break;
			case 60:
				s3v = 2;
				break;	
			default:
				s3v = 0;
				break;
		}
		
		switch (e4S) {
			case 50:
				s4v = 0;
				break;
			case 75:
				s4v = 1;
				break;
			case 100:
				s4v = 2;
				break;
			default:
				s4v = 0;
				break;
		}
		
		int[] scorePos = {s0v, s1v, s2v, s3v, s4v};
		
		String s0C = PlayerPrefs.GetString("e0Col", "default");
		String s1C = PlayerPrefs.GetString("e1Col", "default");
		String s2C = PlayerPrefs.GetString("e2Col", "default");
		String s3C = PlayerPrefs.GetString("e3Col", "default");
		String s4C = PlayerPrefs.GetString("e4Col", "default");

		String[] setCols = {s0C, s1C, s2C, s3C, s4C};

		for (int i = 0; i < 5; i++) {
			scoreDropdown[i].captionText.text = setScores[i].ToString();
			scoreDropdown[i].value = scorePos[i];
		}

		for (int i = 0; i < 5; i++) {
						
			switch (setCols[i]) {
			
				case "def":
					colourDropdown[i].captionText.text = "Default";
					colourDropdown[i].value = 0;
					break;
				case "red":
					colourDropdown[i].captionText.text = "Magenta";
					colourDropdown[i].value = 1;
					break;
				case "grn":
					colourDropdown[i].captionText.text = "Green";
					colourDropdown[i].value = 2;
					break;
				case "blu":
					colourDropdown[i].captionText.text = "Blue";
					colourDropdown[i].value = 3;
					break;
			}
		}
	}
	
}
