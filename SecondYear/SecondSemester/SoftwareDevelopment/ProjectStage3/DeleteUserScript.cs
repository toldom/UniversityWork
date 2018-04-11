using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class DeleteUserScript : MonoBehaviour {

	[Header("Input Fields")] 
	public InputField UserNameField;

	[Header("Text objects")] 
	public Text SuccessText;
	public Text UserDoesNotExist;
	
	//Private variables
	private string _username;
	private string _path;
	private string _loadedUserData;

	private UserData _user;
	public Image BgImage;

	public Sprite Default, city, mountain, lion;

	private void Awake() {
		
		SuccessText.gameObject.SetActive(false);
		UserDoesNotExist.gameObject.SetActive(false);
		
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
	
	private bool CheckUserExists(string path) {
		if (File.Exists(path)) {
			return true;
		}
		
		UserDoesNotExist.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
		return false;
	}

	public void DeleteUser() {

		_username = UserNameField.text;
		_path = Application.streamingAssetsPath + "/" + _username + ".json";

		if (!CheckUserExists(_path)) return;
		
		if (File.Exists(_path)) File.Delete(_path);
		
		SuccessText.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
	}
	
	private IEnumerator HideTextsAfterDelay() {
		yield return new WaitForSeconds(3);

		SuccessText.gameObject.SetActive(false);
		UserDoesNotExist.gameObject.SetActive(false);
	}

	public void MainMenuButtonFunc() {
		SceneManager.LoadScene("_Scene_MainMenu");
		
    }
}