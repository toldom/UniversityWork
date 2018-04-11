/*
 * Project Stage 1 : Space SHMUP
 * Marcus Toldo - 104623006
 * Friday, February 16, 2017
 */

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Random = UnityEngine.Random;

public class Main : MonoBehaviour {

	static public Main S;
	
	public GameObject backgroundPanel;
	public Material[] materialArray;

	private static Dictionary<WeaponType, WeaponDefinition> WEAP_DICT;

	[Header("Set in Inspector")] 
	public GameObject[] prefabEnemies;
	public float enemySpawnPerSecond = 0.5f;
	public float enemyDefaultPadding = 1.5f;
	public WeaponDefinition[] weaponDefinitions;
	public GameObject prefabPowerUp;
	public WeaponType[] powerUpFrequence = new WeaponType[] {
		WeaponType.blaster, WeaponType.blaster, WeaponType.spread, WeaponType.shield
	};

	public Text scoreText, e0KillText, e1KillText, e2KillText, e3KillText, e4KillText, levelText, timeText; 

	private BoundsCheck bndCheck;

	private Color col;
	private int score, e0Kills, e1Kills, e2Kills, e3Kills, e4Kills, time;

	public void ShipDestroyed(Enemy e) {
		if (Random.value <= e.powerUpDropChance) {
			print("AM DROPPING MIXTAPE");
			int ndx = Random.Range(0, powerUpFrequence.Length);
			WeaponType puType = powerUpFrequence[ndx];
			
			GameObject go = Instantiate(prefabPowerUp) as GameObject;
			PowerUp pu = go.GetComponent<PowerUp>();
			pu.SetType(puType);

			pu.transform.position = e.transform.position;
		}

		string substring = e.name.Substring(6, 1);

		switch (substring) {
			case "0":
				e0Kills++;
				score += PlayerPrefs.GetInt("e0Score");
				break;
				
			case "1":
				e1Kills++;
				score += PlayerPrefs.GetInt("e1Score");
				break;
				
			case "2":
				e2Kills++;
				score += PlayerPrefs.GetInt("e2Score");
				break;
				
			case "3":
				e3Kills++;
				score += PlayerPrefs.GetInt("e3Score");
				break;
				
			case "4":
				e4Kills++;
				score += PlayerPrefs.GetInt("e4Score");
				break;
		}
	}

	private void updateTexts() {
		scoreText.text = "Score: " + score;
		e0KillText.text = "e0 kills: " + e0Kills;
		e1KillText.text = "e1 kills: " + e1Kills;
		e2KillText.text = "e2 kills: " + e2Kills;
		e3KillText.text = "e3 kills: " + e3Kills;
		e4KillText.text = "e4 kills: " + e4Kills;
		levelText.text = "Bronze";
		timeText.text = Math.Ceiling(Time.timeSinceLevelLoad).ToString();
	}

	private void Awake() {

		S = this;
		bndCheck = GetComponent<BoundsCheck>();
		Invoke("SpawnEnemy", 1f/enemySpawnPerSecond);
		
		WEAP_DICT = new Dictionary<WeaponType, WeaponDefinition>();
		foreach (WeaponDefinition def in weaponDefinitions) {
			WEAP_DICT[def.type] = def;
		}
		
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
		
		String e0Col = PlayerPrefs.GetString("e0Col", "def");

		score = PlayerPrefs.GetInt("tempScore", 0);
		e0Kills = PlayerPrefs.GetInt("e0Kill", 0);
		e1Kills = PlayerPrefs.GetInt("e1Kill", 0);
		e2Kills = PlayerPrefs.GetInt("e2Kill", 0);
		e3Kills = PlayerPrefs.GetInt("e3Kill", 0);
		e4Kills = PlayerPrefs.GetInt("e4Kill", 0);
		time = PlayerPrefs.GetInt("currentTime", 0);
		levelText.text = PlayerPrefs.GetString("currentLevel", "Silver");
	}

	private void Update() {
		updateTexts();

		if (score >= PlayerPrefs.GetInt("SilverScoreThreshold") && PlayerPrefs.GetInt("bronzeFlag", 1) == 1) {
			
			PlayerPrefs.SetInt("bronzeFlag", 0);
			
			PlayerPrefs.SetInt("tempScore", score);
			PlayerPrefs.SetInt("e0Kill", e0Kills);
			PlayerPrefs.SetInt("e1Kill", e1Kills);
			PlayerPrefs.SetInt("e2Kill", e2Kills);
			PlayerPrefs.SetInt("e3Kill", e3Kills);
			PlayerPrefs.SetInt("e4Kill", e4Kills);
			PlayerPrefs.SetInt("currentTime", (int)Math.Ceiling(Time.timeSinceLevelLoad));
			PlayerPrefs.SetString("currentLevel", "Silver");
			
			SceneManager.LoadScene("_Scene_0");
		}

	}

	public void SpawnEnemy() {
		int ndx = Random.Range(0, prefabEnemies.Length);
		GameObject go = Instantiate<GameObject>(prefabEnemies[ndx]);

		float enemyPadding = enemyDefaultPadding;
		if (go.GetComponent<BoundsCheck>() != null) {
			enemyPadding = Mathf.Abs(go.GetComponent<BoundsCheck>().radius);
		}

		Vector3 pos = Vector3.zero;
		float xMin = -bndCheck.camWidth + enemyPadding;
		float xMax = bndCheck.camWidth - enemyPadding;
		pos.x = Random.Range(xMin, xMax);
		pos.y = bndCheck.camHeight + enemyPadding;
		go.transform.position = pos;

		String enemyNum = go.name.Substring(6, 1);
		print(enemyNum);
		int enemyNumInt = Int32.Parse(enemyNum);

		switch (enemyNumInt) {

			case 0:
				switch (PlayerPrefs.GetString("e0Col", "def")) {
					case "def":
						col = Color.white;
						break;
					case "red":
						col = Color.magenta;
						break;
					case"grn":
						col = Color.green;
						break;
					case "blu":
						col = Color.blue;
						break;
				}

				break;

			case 1:
				switch (PlayerPrefs.GetString("e1Col", "def")) {
					case "def":
						col = Color.white;
						break;
					case "red":
						col = Color.magenta;
						break;
					case"grn":
						col = Color.green;
						break;
					case "blu":
						col = Color.blue;
						break;
				}

				break;

			case 2:
				switch (PlayerPrefs.GetString("e2Col", "def")) {
					case "def":
						col = Color.white;
						break;
					case "red":
						col = Color.magenta;
						break;
					case"grn":
						col = Color.green;
						break;
					case "blu":
						col = Color.blue;
						break;
				}

				break;

			case 3:
				switch (PlayerPrefs.GetString("e3Col", "def")) {
					case "def":
						col = Color.white;
						break;
					case "red":
						col = Color.magenta;
						break;
					case"grn":
						col = Color.green;
						break;
					case "blu":
						col = Color.blue;
						break;
				}

				break;

			case 4:
				switch (PlayerPrefs.GetString("e4Col", "def")) {
					case "def":
						col = Color.white;
						break;
					case "red":
						col = Color.magenta;
						break;
					case"grn":
						col = Color.green;
						break;
					case "blu":
						col = Color.blue;
						break;
				}

				break;
		}

		foreach (Transform part in go.transform) {
			part.GetComponent<Renderer>().material.color = col;
		}
		
		go.SendMessage("ResetMaterialLists");
					
		Invoke("SpawnEnemy", 1f/enemySpawnPerSecond);
	}

	public void DelayedRestart(float delay) {
		
		Invoke("Restart", delay);
	}

	public void Restart() {
		
		PlayerPrefs.SetInt("tempScore", 0);
		PlayerPrefs.SetInt("e0Kill", 0);
		PlayerPrefs.SetInt("e1Kill", 0);
		PlayerPrefs.SetInt("e2Kill", 0);
		PlayerPrefs.SetInt("e3Kill", 0);
		PlayerPrefs.SetInt("e4Kill", 0);
		PlayerPrefs.SetInt("currentTime", 0);
		PlayerPrefs.SetInt("bronzeFlag", 1);
		PlayerPrefs.SetInt("silverFlag", 1);
		PlayerPrefs.SetString("currentLevel", "Bronze");
		
		SceneManager.LoadScene("_Scene_0");
	}

	static public WeaponDefinition GetWeaponDefinition(WeaponType wt) {
		if (WEAP_DICT.ContainsKey(wt)) {
			return WEAP_DICT[wt];
		}

		return new WeaponDefinition();
	}
}
