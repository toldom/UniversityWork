/*												*
 * 		Software Development - 03-60-280		*
 * 		Assignment 2 - Rock Paper Scissors		*
 * 		Marcus Toldo - 104623006				*
 * 		Monday, February 12, 2018				*
 *												*/

using UnityEngine;
using UnityEngine.SceneManagement;

public class InfoScript : MonoBehaviour {

	/*
	 * Objective: Public function that is used by the menu button to return the user back to the games main menu
	 */
	public void BackButton() {
		SceneManager.LoadScene("_Scene_MainMenuRPS");
	}
}
