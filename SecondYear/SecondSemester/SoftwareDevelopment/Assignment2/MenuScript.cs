/*												*
 * 		Software Development - 03-60-280		*
 * 		Assignment 2 - Rock Paper Scissors		*
 * 		Marcus Toldo - 104623006				*
 * 		Monday, February 12, 2018				*
 *												*/

using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuScript : MonoBehaviour {

	/*
	 * Objective: This is a public function to be called by the 'Play Game' button in the main menu, which will load the
	 * game scene
	 */
	public void StartGame() {
	
		SceneManager.LoadScene("_Scene_GameViewRPS");
		
	}

	/*
	 * Objective: This is a public function to be called by the 'Information ' button in the main menu, which will load the
	 * information scene
	 */
	public void LoadInfo() {
		SceneManager.LoadScene("_Scene_InfoScene");
	}
}