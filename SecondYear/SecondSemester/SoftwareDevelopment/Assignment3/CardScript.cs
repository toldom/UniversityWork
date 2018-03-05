using System.Collections;
using UnityEngine;

public class CardScript : MonoBehaviour {

	public bool isFlipped;
	private float rotSpeed = 10f;
	public AudioClip selectSound;

	private AudioSource audio;
	private bool playSound = true;

	private void Awake() {
		isFlipped = false;
		audio = GetComponent<AudioSource>();
	}

	private void OnMouseDown() {
		
		//Flips the card when it is clicked, and indicates that
		gameObject.transform.Rotate(new Vector3(0, 180, 0));
		isFlipped = !isFlipped;
		
		//Tells the main script that a card has been clicked
		GameObject.Find("Main Camera").SendMessage("CardFlipTrigger");

		
		//Plays the appropriate audio clip
		audio.PlayOneShot(selectSound);

	}

	/*
	 * Objective: Public function that is triggered by main script, flips the card back over
	 */
	public void ResetFlip() {

		StartCoroutine(ActualFlipReset());
	}

	/*
	 * Objective: Flips the card back over to show the card back after a 2 second delay, frees the mouse
	 */
	private IEnumerator ActualFlipReset() {

		yield return new WaitForSeconds(1);
		
		gameObject.transform.Rotate(new Vector3(0, -180, 0));
		isFlipped = false;

		Cursor.visible = true;
		Cursor.lockState = CursorLockMode.None;
	}

	
}
 