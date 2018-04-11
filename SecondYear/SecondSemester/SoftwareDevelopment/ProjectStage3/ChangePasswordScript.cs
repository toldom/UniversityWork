using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ChangePasswordScript : MonoBehaviour {

	[Header("Input Fields")] 
	public InputField PasswordField;
	public InputField ConfirmPasswordField;

	[Header("Text objects")] 
	public Text SuccessText;
	public Text PasswordsDontMatch;

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
		return false;
	}

	public void ChangePasswordButtonFunc() {
		if (!CheckPasswordEquity()) {
			PasswordsDontMatch.gameObject.SetActive(true);
			StartCoroutine(HideTextsAfterDelay());
			return;
		}

		_user = PlayerPrefs.GetString("currentUser");
		_path = Application.streamingAssetsPath + "/" + _user + ".json";
		_loadedData = File.ReadAllText(_path);
		_loadedUser = JsonUtility.FromJson<UserData>(_loadedData);

		_loadedUser.Password = PasswordField.text;
		_loadedUser.NewAccount = false;

		string[] dataToSave = {JsonUtility.ToJson(_loadedUser)};
		File.WriteAllLines(_path, dataToSave);

		SuccessText.gameObject.SetActive(true);
		StartCoroutine(HideTextsAfterDelay());
	}

	private IEnumerator HideTextsAfterDelay() {
		yield return new WaitForSeconds(3);

		SuccessText.gameObject.SetActive(false);
		PasswordsDontMatch.gameObject.SetActive(false);
	}
	
	public void MainMenuButtonFunc() {
		SceneManager.LoadScene("_Scene_MainMenu");
	}
	
}
