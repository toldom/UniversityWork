/*                                                                 *
 * 03-60-280 - Software Development                                *
 * Term Project Stage 3 - Login.cs                                 *
 * Created by Marcus Toldo on Friday, April 6, 2018                *
 * Last modified by Marcus Toldo on Wednesday, March 28, 2018      *
 *                                                                 */

using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Button = UnityEngine.UI.Button;

public class MainMenu : MonoBehaviour {

	[Header("Options Sub Buttons")]
	public Button UserAccountsButton;
	public Button ConfigurationsButton;
	public Button HistoryButton;
	public Button LogoutButton;

	[Header("UserAccounts Sub Buttons")] 
	public Button CreateUserButton;
	public Button DeleteUserButton;
	public Button ChangePasswordButton;
	public Button ReleaseBlocksButton;

	[Header("Configuration sub buttons")] 
	public Button AudioButton;
	public Button BackgroundButton;
	public Button CloseMenusButton;

	[Header("SHMUP sub buttons")] 
	public Button SHMUPGameLevelsButton;
	public Button SHMUPConfigurationsButton;
	public Button SHMUPHistoryButton;
	public Button SHMUPPlayButton;
	public Button SHMUPCloseMenuButton;

	[Header("Apple Picker sub buttons")] 
	public Button ApplePickerHistoryButton;
	public Button ApplePickerPlayButton;
	public Button ApplePickerCloseMenuButton;

	[Header("RPS sub buttons")] 
	public Button RPSHistoryButton;
	public Button RPSInfoButton;
	public Button RPSPlayButton;
	public Button RPSCloseMenuButton;
	
	[Header("Memory game sub buttons")] 
	public Button MemoryGameHistoryButton;
	public Button MemoryGameSettingsButton;
	public Button MemoryGamePlayButton;
	public Button MemoryGameCloseMenuButton;
	
	[Header("UI Error Texts")]
	public Text AdminOnlyErrorText;
	
	
	//Private variables
	private bool _showingOptionSubButtons;
	private bool _showingUserAccountSubButtons;
	private bool _showingConfigurationSubButtons;
	private bool _showingSHMUPSubButtons;
	private bool _showingApplePickerSubButtons;
	private bool _showingRPSSubButtons;
	private bool _showingMemoryGameSubButtons;
	
	public Image BgImage;

	public Sprite Default, city, mountain, lion;

	private void Awake() {
		//Options Sub buttons
		UserAccountsButton.gameObject.SetActive(false);
		ConfigurationsButton.gameObject.SetActive(false);
		HistoryButton.gameObject.SetActive(false);
		LogoutButton.gameObject.SetActive(false);
		
		//UserAccounts Sub Buttons
		CreateUserButton.gameObject.SetActive(false);
		DeleteUserButton.gameObject.SetActive(false);
		ChangePasswordButton.gameObject.SetActive(false);
		ReleaseBlocksButton.gameObject.SetActive(false);
		
		//Configuration Sub Buttons
		AudioButton.gameObject.SetActive(false);
		BackgroundButton.gameObject.SetActive(false);
		CloseMenusButton.gameObject.SetActive(false);
		
		//SHMUP Sub buttons
		SHMUPGameLevelsButton.gameObject.SetActive(false);
		SHMUPConfigurationsButton.gameObject.SetActive(false);
		SHMUPHistoryButton.gameObject.SetActive(false);
		SHMUPPlayButton.gameObject.SetActive(false);
		SHMUPCloseMenuButton.gameObject.SetActive(false);
		
		//Apple Picker sub buttons 
		ApplePickerHistoryButton.gameObject.SetActive(false);
		ApplePickerPlayButton.gameObject.SetActive(false);
		ApplePickerCloseMenuButton.gameObject.SetActive(false);
		
		//RPS sub buttons
		RPSHistoryButton.gameObject.SetActive(false);
		RPSInfoButton.gameObject.SetActive(false);
		RPSPlayButton.gameObject.SetActive(false);
		RPSCloseMenuButton.gameObject.SetActive(false);
		
		//Memory game sub buttons
		MemoryGameHistoryButton.gameObject.SetActive(false);
		MemoryGameSettingsButton.gameObject.SetActive(false);
		MemoryGamePlayButton.gameObject.SetActive(false);
		MemoryGameCloseMenuButton.gameObject.SetActive(false);
		
		//Error texts
		AdminOnlyErrorText.gameObject.SetActive(false);
		
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

	/*
	 * Description: Show all options sub buttons on clicking options button
	 */
	public void OptionsButton() {

		switch (_showingOptionSubButtons) {
			case false:
				UserAccountsButton.gameObject.SetActive(true);
                ConfigurationsButton.gameObject.SetActive(true);
                HistoryButton.gameObject.SetActive(true);
                LogoutButton.gameObject.SetActive(true);
				_showingOptionSubButtons = true;
				break;
				
			case true:
				UserAccountsButton.gameObject.SetActive(false);
				ConfigurationsButton.gameObject.SetActive(false);
				HistoryButton.gameObject.SetActive(false);
				LogoutButton.gameObject.SetActive(false);
				_showingOptionSubButtons = false;
				break;
		}
		
	}

	/*
	 * ObjecDescriptiontive: Show all options sub buttons on clicking options button
	 */
	public void UserAccountsButtonFunc() {

		switch (_showingUserAccountSubButtons) {
			case false:
				CreateUserButton.gameObject.SetActive(true);
				DeleteUserButton.gameObject.SetActive(true);
				ChangePasswordButton.gameObject.SetActive(true);
				ReleaseBlocksButton.gameObject.SetActive(true);
				_showingUserAccountSubButtons = true;
				break;
				
			case true:
				CreateUserButton.gameObject.SetActive(false);
				DeleteUserButton.gameObject.SetActive(false);
				ChangePasswordButton.gameObject.SetActive(false);
				ReleaseBlocksButton.gameObject.SetActive(false);
				_showingUserAccountSubButtons = false;
				break;
		}
		
	}
	
	/*
	 * Description: Show all configurations sub buttons on clicking confogurations button
	 */
	public void ConfigurationsButtonFunc() {
	
		switch (_showingConfigurationSubButtons) {
			case false:
				AudioButton.gameObject.SetActive(true);
				BackgroundButton.gameObject.SetActive(true);
				CloseMenusButton.gameObject.SetActive(true);
				_showingConfigurationSubButtons = true;
				break;
				
			case true:
				AudioButton.gameObject.SetActive(false);
				BackgroundButton.gameObject.SetActive(false);
				CloseMenusButton.gameObject.SetActive(false);
				_showingConfigurationSubButtons = false;
				break;
		}
						
	}
	
	/*
	 * Description: Show all SHMUP sub buttons
	 */
	public void SHMUPButtonFunc() {
	
		switch (_showingSHMUPSubButtons) {
			case false:
				SHMUPGameLevelsButton.gameObject.SetActive(true);
				SHMUPConfigurationsButton.gameObject.SetActive(true);
				SHMUPHistoryButton.gameObject.SetActive(true);
				SHMUPPlayButton.gameObject.SetActive(true);
				SHMUPCloseMenuButton.gameObject.SetActive(true);
				_showingSHMUPSubButtons = true;
				break;
				
			case true:
				SHMUPGameLevelsButton.gameObject.SetActive(false);
				SHMUPConfigurationsButton.gameObject.SetActive(false);
				SHMUPHistoryButton.gameObject.SetActive(false);
				SHMUPPlayButton.gameObject.SetActive(false);
				SHMUPCloseMenuButton.gameObject.SetActive(false);
				_showingSHMUPSubButtons = false;
				break;
		}
						
	}
	
	/*
	 * Description: Show all Apple Picker sub buttons
	 */
	public void ApplePickerButtonFunc() {
	
		switch (_showingApplePickerSubButtons) {
			case false:
				ApplePickerHistoryButton.gameObject.SetActive(true);
				ApplePickerPlayButton.gameObject.SetActive(true);
				ApplePickerCloseMenuButton.gameObject.SetActive(true);
				_showingApplePickerSubButtons = true;
				break;
				
			case true:
				ApplePickerHistoryButton.gameObject.SetActive(false);
				ApplePickerPlayButton.gameObject.SetActive(false);
				ApplePickerCloseMenuButton.gameObject.SetActive(false);
				_showingApplePickerSubButtons = false;
				break;
		}
						
	}

	public void BackgroundButtonFunc() {
		SceneManager.LoadScene("_Scene_Wallpaper");
	}
	
	/*
	 * Description: Show all RPS sub buttons
	 */
	public void RPSButtonFunc() {
	
		switch (_showingRPSSubButtons) {
			case false:
				RPSHistoryButton.gameObject.SetActive(true);
				RPSInfoButton.gameObject.SetActive(true);
				RPSPlayButton.gameObject.SetActive(true);
				RPSCloseMenuButton.gameObject.SetActive(true);
				_showingRPSSubButtons = true;
				break;
				
			case true:
				RPSHistoryButton.gameObject.SetActive(false);
				RPSInfoButton.gameObject.SetActive(false);
				RPSPlayButton.gameObject.SetActive(false);
				RPSCloseMenuButton.gameObject.SetActive(false);
				_showingRPSSubButtons = false;
				break;
		}
						
	}

	/*
	 * Description: Show all memory game sub buttons
	 */
	public void MemoryGameButtonFunc() {
	
		switch (_showingMemoryGameSubButtons) {
			case false:
				MemoryGameHistoryButton.gameObject.SetActive(true);
				MemoryGameSettingsButton.gameObject.SetActive(true);
				MemoryGamePlayButton.gameObject.SetActive(true);
				MemoryGameCloseMenuButton.gameObject.SetActive(true);
				_showingMemoryGameSubButtons = true;
				break;
				
			case true:
				MemoryGameHistoryButton.gameObject.SetActive(false);
				MemoryGameSettingsButton.gameObject.SetActive(false);
				MemoryGamePlayButton.gameObject.SetActive(false);
				MemoryGameCloseMenuButton.gameObject.SetActive(false);
				_showingMemoryGameSubButtons = false;
				break;
		}
						
	}
	
	/*
	 * Description: Shows the history scene
	 */
	public void HistoryButtonFunc() {
		SceneManager.LoadScene("_Scene_History");
	}

	/*
	 * Description: Logs out the user and shows the login screen
	 */
	public void LogoutButtonFunc() {
		SceneManager.LoadScene("_Scene_Login");
	}

	/*
	 * Description: Allows the admin to create a user
	 */
	public void CreateUserButtonFunc() {
		if (CheckIsAdmin(true) == false) return;
		
		SceneManager.LoadScene("_Scene_CreateUser");
	}

	/*
	 * Description: Allows the admin to delete users
	 */
	public void DeleteUserButtonFunc() {
		if (CheckIsAdmin(true) == false) return;

		SceneManager.LoadScene("_Scene_DeleteUser");
	}

	/*
	 * Description: Allows users to change their passwords, allows admin to change any password
	 */
	public void ChangePasswordButtonFunc() {
		if (CheckIsAdmin(false)) {
			SceneManager.LoadScene("_Scene_AdminPasswordManager");
		} else {
			SceneManager.LoadScene("_Scene_ChangePassword");	
		} 
	}

	public void ReleaseBlocksButtonFunc() {
		if (CheckIsAdmin(true) == false) return;
		
		SceneManager.LoadScene("_Scene_ReleaseBlocks");
	}
	
	/*
	 * Description: Loads SHMUP game levels
	 */
	public void SHMUPGameLevelsButtonFunc() {
		SceneManager.LoadScene("_GameLevel_Scene");
	}
	
	/*
	 * Description: Loads SHMUP configuration
	 */
	public void SHMUPConfigurationsButtonFunc() {
		SceneManager.LoadScene("_Config_Scene");
	}
	
	/*
	 * Description: Loads SHMUP history
	 */
	public void SHMUPHistoryButtonFunc() {
		SceneManager.LoadScene("_Scene_History");
	}
	
	/*
	 * Description: Loads SHMUP
	 */
	public void SHMUPPlayGameButtonFunc() {
		SceneManager.LoadScene("_Scene_0");
	}
	
	/*
	 * Description: Closes SHMUP buttons 
	 */
	public void SHMUPCloseMenuFunc() {
		SHMUPGameLevelsButton.gameObject.SetActive(false);
		SHMUPConfigurationsButton.gameObject.SetActive(false);
		SHMUPHistoryButton.gameObject.SetActive(false);
		SHMUPPlayButton.gameObject.SetActive(false);
		SHMUPCloseMenuButton.gameObject.SetActive(false);
		_showingSHMUPSubButtons = false;
	}

	public void ApplePickerPlayButtonFunc() {
		SceneManager.LoadScene("_Scene_GameView");
	}
	
	/*
	 * Description: Closes Apple picker buttons 
	 */
	public void ApplePickerCloseMenuButtonFunc() {
		ApplePickerHistoryButton.gameObject.SetActive(false);
		ApplePickerPlayButton.gameObject.SetActive(false);
		ApplePickerCloseMenuButton.gameObject.SetActive(false);
		_showingApplePickerSubButtons = false;
	}

	public void RPSInfoButtonFunc() {
		SceneManager.LoadScene("_Scene_InfoScene");
	}

	public void RPSPlayButtonFunc() {
		SceneManager.LoadScene("_Scene_GameViewRPS");
	}
	
	/*
	 * Description: Closes RPS buttons 
	 */
	public void RPSCloseMenuButtonFunc() {
		RPSHistoryButton.gameObject.SetActive(false);
		RPSPlayButton.gameObject.SetActive(false);
		RPSCloseMenuButton.gameObject.SetActive(false);
		_showingRPSSubButtons = false;
	}

	public void MemoryGameSettingsButtonFunc() {
		SceneManager.LoadScene("_Settings");
	}

	public void MemoryGamePlayButtonFunc() {
		SceneManager.LoadScene("_GameView");
	}
	
	/*
	 * Description: Closes memory game buttons 
	 */
	public void MemoryGameCloseMenuButtonFunc() {
		MemoryGameHistoryButton.gameObject.SetActive(false);
		MemoryGamePlayButton.gameObject.SetActive(false);
		MemoryGameCloseMenuButton.gameObject.SetActive(false);
		_showingMemoryGameSubButtons = false;
	}
	
	/*
	 * Description: Checks if the user is the admin, if not, displays an error
	 */
	private bool CheckIsAdmin(bool error) {
		if (PlayerPrefs.GetString("currentUser") != "admin") {
			if (error) {
				AdminOnlyErrorText.gameObject.SetActive(true);
                StartCoroutine(HideTexts());
			}
			
			return false;
		}

		return true;
	}

	/*
	 * Description: Hides all error texts after 3 seconds
	 */
	public IEnumerator HideTexts() {
		yield return new WaitForSeconds(3);
		
		AdminOnlyErrorText.gameObject.SetActive(false);
	}
	
}
