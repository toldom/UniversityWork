using System;
using UnityEditor;
using UnityEngine;

public class Audio : MonoBehaviour {

	public AudioSource source;
	public AudioClip[] audioClips;


	void Start () {
		DontDestroyOnLoad(gameObject);
	}

	public void SetAudioClip(int input) {
		switch (input) {
			case 0:
				source.Stop();
				source.clip = audioClips[0];
				source.Play();
				break;
			case 1:
				source.Stop();
				source.clip = audioClips[2];
				source.Play();
				break;
			case 2:
				source.Stop();
				source.clip = audioClips[3];
				source.Play();
				break;
			case 3:
				source.Stop();
				source.clip = audioClips[1];
				break;
		}
	}
	
	
}
