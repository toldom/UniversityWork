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
		gameObject.transform.Rotate(new Vector3(0, 180, 0));
		isFlipped = !isFlipped;
		GameObject.Find("Main Camera").SendMessage("CardFlipTrigger");

		if (playSound) {
			audio.PlayOneShot(selectSound);

		}

	}

	public void ResetFlip() {

		StartCoroutine(ActualFlipReset());
		//audio.mute = false;

	}

	/*public void MuteSound() {
		playSound = false;
	}*/

	private IEnumerator ActualFlipReset() {

		yield return new WaitForSeconds(1);
		
		gameObject.transform.Rotate(new Vector3(0, -180, 0));
		isFlipped = false;

		Cursor.visible = true;
		Cursor.lockState = CursorLockMode.None;
	}

	
}
 