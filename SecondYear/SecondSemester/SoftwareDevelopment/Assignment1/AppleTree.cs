using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AppleTree : MonoBehaviour {

	public GameObject applePrefab;					//The Apple object
	public float speed = 1f;						//Speed at which the tree moves
	public float leftAndRightEdge = 10f;			//
	public float chanceToChangeDirections = 0.1f;	//% chance of changing directions
	public float appleDropRate = 1f; 				//In Seconds

	private bool extraApples;
	private int extraAppleClock;

	// Use this for initialization
	void Start () {
		//Begin dropping apples accoriding to drop rate
		InvokeRepeating("DropApple", 0f, appleDropRate);

		extraApples = false;
		extraAppleClock = 90;
	}

	// Update is called once per frame
	void Update () {
		
		//Move the tree
		Vector3 pos = transform.position;
		pos.x += speed * Time.deltaTime;
		transform.position = pos;

		//Change direction
		if (pos.x < -leftAndRightEdge) {
			speed = Mathf.Abs (speed);
		} else if (pos.x > leftAndRightEdge) {
			speed = -Mathf.Abs (speed);
		} 

	}

	void FixedUpdate() {
		if (Random.value <= chanceToChangeDirections) {
			speed *= -1;
		}

		if (extraApples) {
			extraAppleClock--;

			if (extraAppleClock <= 0) {
				DropApple();
				extraAppleClock = 90;
			}
		}
	}

	void DropApple() {

		GameObject apple = Instantiate (applePrefab) as GameObject;
		apple.transform.position = transform.position;
	}

	void IncreaseDificulty() {
		if (speed > 0) {
			speed += 20;
		} else {
			speed -= 20;
		}
	}

	void IncreaseDificulty2() {
		extraApples = true;
	}

}
