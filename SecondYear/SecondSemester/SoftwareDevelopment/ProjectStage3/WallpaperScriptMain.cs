using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class WallpaperScriptMain : MonoBehaviour {

	public Dropdown Dropdown;
	public Image Image, BgImage;


	public Sprite Default, city, mountain, lion;

	private void Awake() {
		Image.sprite = Default;

		switch (PlayerPrefs.GetString("wallpaper", "Default")) {
			case "Default":
				BgImage.sprite = Default;
				break;
				
			case "City":
				BgImage.sprite = city;
				break;
				
			case "Mountain":
				BgImage.sprite = mountain;
				break;
				
			case "Lion":
				BgImage.sprite = lion;
				break;
		}
	}

	private void Update() {
		if (Dropdown.captionText.text == "Default") {
			Image.sprite = Default;
		} else if (Dropdown.captionText.text == "City") {
			Image.sprite = city;
		} else if (Dropdown.captionText.text == "Mountain") {
			Image.sprite = mountain;
		}
		else {
			Image.sprite = lion;
		}
		
	}

	public void ChangeButton() {
		PlayerPrefs.SetString("wallpaper", Dropdown.captionText.text);
		SceneManager.LoadScene("_Scene_Wallpaper");
	}

	public void MenuButton() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}
	
}
