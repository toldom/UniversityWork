using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DylanTreeScript : MonoBehaviour {

	// Use this for initialization
	//prefab for instantiating apple
	public GameObject applePrefab;

	//Speed at which the appleTree moves in meters a sec
	public float speed=1f;

	//Distance where AppleTree turns around
	public float leftAndRightEdge=10f;

	//chance that the AppleTree will change directions
	public float chanceToChangeDirections=0.1f;

	//Rate at which Apples will be instantiated
	public float secondsBetweenAppleDrops=1f;
	void Start () {
		//dropping apples every second

	}

	// Update is called once per frame
	void Update () {
		//basic movement
		//changing directions

	}
}
