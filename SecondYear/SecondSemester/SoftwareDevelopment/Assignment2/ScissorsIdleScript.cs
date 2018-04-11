/*												*
 * 		Software Development - 03-60-280		*
 * 		Assignment 2 - Rock Paper Scissors		*
 * 		Marcus Toldo - 104623006				*
 * 		Monday, February 12, 2018				*
 *												*/

using UnityEngine;

public class ScissorsIdleScript : MonoBehaviour {

	// Update is called once per frame
	void Update () {
		
		//Roatetes the 3D object right, to indicate that it can be clicked
		transform.Rotate(Vector3.forward, Time.deltaTime*50);
	}

	/*
	 * Objective: This function sends a message to the 'MainScript' that scissors has been clocked, and that it is to
	 * 			  execute the 'ScissorsClicked' function
	 */
	private void OnMouseDown() {		
		GameObject.Find("Main Camera").SendMessage("ScissorsClicked");
	}
}
