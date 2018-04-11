using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class AdminPasswordManager : MonoBehaviour {

	[Header("Input Fields")] 
	public InputField UsernameField;
	public InputField PasswordField;
	public InputField ConfirmPasswordField;

	[Header("Text objects")] 
	public Text SuccessText;
	public Text PasswordsDontMatch;
	public Text UserDoesNotExist;

	//private variables
	private string _user;
	private string _loadedData;
	private string _path;

	private UserData _loadedUser;
	
	
	public Image BgImage;

	public Sprite Default, city, mountain, lion;

	private void Awake() {
		
		SuccessText.gameObject.SetActive(false);
		PasswordsDontMatch.gameObject.SetActive(false);
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

	private bool CheckPasswordEquity() {
		if (PasswordField.text == ConfirmPasswordField.text) return true;
		
		PasswordsDontMatch.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
		
		return false;
	}

	private bool CheckUserExists(string path) {

		if (File.Exists(path)) return true;

		return false;

	}

	public void ChangePasswordButtonFunc() {
		
		_user = UsernameField.text;
		_path = Application.streamingAssetsPath + "/" + _user + ".json";

		if (!CheckUserExists(_path)) {
			UserDoesNotExist.gameObject.SetActive(true);
			StartCoroutine(HideTextsAfterDelay());
			return;
		}

		if (!CheckPasswordEquity()) {
			PasswordsDontMatch.gameObject.SetActive(true);
			StartCoroutine(HideTextsAfterDelay());
			return;
		}

		_loadedData = File.ReadAllText(_path);

		_loadedUser = JsonUtility.FromJson<UserData>(_loadedData);

		_loadedUser.Password = PasswordField.text;

		string[] toJson = {JsonUtility.ToJson(_loadedUser)};
		File.WriteAllLines(_path, toJson);
		
		SuccessText.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
	}
	
	private IEnumerator HideTextsAfterDelay() {
		yield return new WaitForSeconds(3);

		SuccessText.gameObject.SetActive(false);
		PasswordsDontMatch.gameObject.SetActive(false);
		UserDoesNotExist.gameObject.SetActive(false);
	}
	
	public void MainMenuButtonFunc() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}
	
}
