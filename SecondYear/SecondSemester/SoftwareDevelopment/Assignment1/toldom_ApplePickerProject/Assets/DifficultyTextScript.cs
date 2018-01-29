using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DifficultyTextScript : MonoBehaviour {
	
	private int hideTime;
	private bool isShowing;
	
	// Use this for initialization
	void Start () {
		hideTime = 60;
		isShowing = false;
	}
	
	// Update is called once per frame
	void Update () {

		if (isShowing) {
			hideTime--;
			if (hideTime == 0) {
				Hide();
			}
		}
		
	}

	void Display() {
		transform.SetAsLastSibling();
		isShowing = true;
	}

	void Hide() {
		transform.SetAsFirstSibling();
		hideTime = 60;
		isShowing = false;
	}
}
