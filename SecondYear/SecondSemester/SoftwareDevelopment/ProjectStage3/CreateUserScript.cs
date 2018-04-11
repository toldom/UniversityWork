using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Button = UnityEngine.UI.Button;

public class CreateUserScript : MonoBehaviour {

	[Header("Input Fields")] 
	public InputField UserNameInput;

	[Header("Text objetcs")] 
	public Text SuccessText;
	public Text NoUserName;
	public Text UserAlreadyExists;
	
	//private variables
	private string _username;
	private string _path;
	
	public Image BgImage;

	public Sprite Default, city, mountain, lion;

	private void Awake() {
		
		SuccessText.gameObject.SetActive(false);
		NoUserName.gameObject.SetActive(false);
		UserAlreadyExists.gameObject.SetActive(false);
		
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
			UserAlreadyExists.gameObject.SetActive(true);
			StartCoroutine(HideTextsAfterDelay());
			return true;
		}

		return false;
	}

	public void CreateUserButtonFunc() {
		if (UserNameInput.text == "") {
			NoUserName.gameObject.SetActive(true);
			StartCoroutine(HideTextsAfterDelay());
			return;
		}
		
		_username = UserNameInput.text;
		_path = Application.streamingAssetsPath + "/" + _username + ".json";

		if (CheckUserExists(_path)) {
			return;
		}
		
		UserData newUser = new UserData();
		newUser.Username = _username;
		newUser.Password = _username;
		newUser.AccountLocked = false;
		newUser.NewAccount = true;

		string[] toJson = {JsonUtility.ToJson(newUser)};
		File.WriteAllLines(_path, toJson);
		
		SuccessText.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
	}
	
	private IEnumerator HideTextsAfterDelay() {
		yield return new WaitForSeconds(3);

		SuccessText.gameObject.SetActive(false);
		NoUserName.gameObject.SetActive(false);
		UserAlreadyExists.gameObject.SetActive(false);
	}
	
	public void MainMenuButtonFunc() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}
	
}
