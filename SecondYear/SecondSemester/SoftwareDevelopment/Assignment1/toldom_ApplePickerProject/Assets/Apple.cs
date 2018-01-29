using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Apple : MonoBehaviour {

	public static float bottomY = -16f;

	// Update is called once per frame
	void Update () {
		if (transform.position.y < bottomY) {
			Destroy (this.gameObject);

            GameObject.Find("Main Camera").SendMessage("AppleDestroyed");
		}
		
	}
}
