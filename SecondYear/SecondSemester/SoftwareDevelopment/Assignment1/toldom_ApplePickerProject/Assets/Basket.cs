using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Basket : MonoBehaviour {

	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		if (Time.timeScale == 1) {
			Vector3 mousePos2D = Input.mousePosition;
            			mousePos2D.z = -Camera.main.transform.position.z;
            	
            			Vector3 mousePos3D = Camera.main.ScreenToWorldPoint (mousePos2D);
            	
            			Vector3 pos = this.transform.position;
            			pos.x = mousePos3D.x;
            			this.transform.position = pos;
		} else {
			this.transform.position = new Vector3(0, this.transform.position.y, this.transform.position.z);
		}
		
	}

	void OnCollisionEnter(Collision coll) {

		GameObject collidedWith = coll.gameObject;

		if (collidedWith.tag == "Apple") {
			Destroy (collidedWith);

            GameObject.Find("Main Camera").SendMessage("IncrementScoreValue");
		}

	}
		
}
