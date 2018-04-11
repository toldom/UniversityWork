/*                                                                 *
 * 03-60-280 - Software Development                                *
 * Term Project Stage 3 - Login.cs                                 *
 * Created by Marcus Toldo on Wednesday, March 28, 2018            *
 * Last modified by Marcus Toldo on Wednesday, March 28, 2018      *
 *                                                                 */

using System;
using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Button = UnityEngine.UI.Button;

namespace __Scripts {
    
    public class Login : MonoBehaviour {

        [Header("Text Objects"), Tooltip("Error text for when no username is inputted")]
        public Text UnameError;
        [Tooltip("Error text for when no password is inputted")]
        public Text PasswordError;
        [Tooltip("Error text for when incorrect password is provided")]
        public Text IncorrectPasswordErrorText;
        [Tooltip("Error text for when the user account is locked out")]
        public Text UserAccountLockedText;
        [Tooltip("Error text for when the requested user to be logged in does not have an account")]
        public Text UserDoesNotExistText;
        
        [Header("Input Fields")]
        [Tooltip("Data field that contains the user inputted username")]
        public InputField UnameField;
        [Tooltip("Data field that contains the user inputted password")]
        public InputField PasswordField;

        [Header("Button Objects")] 
        public Button LoginButton;
        public Button ExitButton;

        
        private string _username, _password;
        private int _failedLogins;
        
        public Image BgImage;

        public Sprite Default, city, mountain, lion;

        private void Awake() {

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

        public void Start() {
            PasswordError.gameObject.SetActive(false);
            UnameError.gameObject.SetActive(false);
            IncorrectPasswordErrorText.gameObject.SetActive(false);
            UserAccountLockedText.gameObject.SetActive(false);
            UserDoesNotExistText.gameObject.SetActive(false);
            
            //PlayerPrefs.SetInt("historyNumber", -1);
        }


        /*
         * Description: Public function to be run when the login button is pressed. Will validate that there is data
         *              inputted, and then check for a corresponding user account.
         */
        public void LoginButtonFunc() {
        
            if (UnameField.text == "") {
                UnameError.gameObject.SetActive(true);
                StartCoroutine(HideErrorTexts());
                return;
            }

            if (PasswordField.text == "") {
                PasswordError.gameObject.SetActive(true);
                StartCoroutine(HideErrorTexts());
                return;
            }

            _username = UnameField.text;
            _password = PasswordField.text;
            
            LoginUser();
        }

        /*
         * Description: Coroutine function that will hide the error texts for both username and password, should they
         *              be showing
         */
        private IEnumerator HideErrorTexts() {
            yield return new WaitForSeconds(3);
        
            PasswordError.gameObject.SetActive(false);
            UnameError.gameObject.SetActive(false);
            IncorrectPasswordErrorText.gameObject.SetActive(false);
            UserAccountLockedText.gameObject.SetActive(false);
            UserDoesNotExistText.gameObject.SetActive(false);
        
        }

        /*
         * Description: Handles logging the user in with the correct credentials
         */
        private void LoginUser() {

            string path = Application.streamingAssetsPath + "/" + _username + ".json";
            
            if (File.Exists(path)) {
                //Do the loggging of the in

                string userData = File.ReadAllText(path);

                UserData user = JsonUtility.FromJson<UserData>(userData);
                
                if (user.AccountLocked) {
                    UserAccountLockedText.gameObject.SetActive(true);
                    StartCoroutine(HideErrorTexts());
                    return;
                }
                
                //Check password validity
                if (_password != user.Password) {
                    IncorrectPasswordErrorText.gameObject.SetActive(true);
                    _failedLogins++;
                    StartCoroutine(HideErrorTexts());

                    if (_failedLogins == 3) {
                        user.AccountLocked = true;
                        string[] toJson = {JsonUtility.ToJson(user)};
                        File.WriteAllLines(Application.streamingAssetsPath + "/" + _username + ".json", toJson);
                        _failedLogins = 0;
                    }
                    
                    return;
                }

                
                
                PlayerPrefs.SetString("currentUser", _username);

                PlayerPrefs.SetInt("historyNumber", PlayerPrefs.GetInt("historyNumber", 0)+1);
                HistoryEntryClass newLogIn = new HistoryEntryClass();
                newLogIn.User = _username;
                newLogIn.EventType = "Login";
                newLogIn.Score = "N/A";
                newLogIn.Time = DateTime.Today.ToString();
                string[] dataToSave = {JsonUtility.ToJson(newLogIn)};
                File.WriteAllLines(Application.streamingAssetsPath + "/HistoryEvents/HistoryEvent" + PlayerPrefs.GetInt("historyNumber") + ".json", dataToSave);

                if (user.NewAccount) {
                    SceneManager.LoadScene("_Scene_ChangePassword");
                } else {
                    SceneManager.LoadScene("_Scene_MainMenu");
                }
                
            } else {
                UserDoesNotExistText.gameObject.SetActive(true);
                StartCoroutine(HideErrorTexts());
            }

        }

        /*
         * Description: Public function to be run when the exit button is clicked. Closes the application. 
         */
        public void ExitButtonFunc() {
            Application.Quit();
        }
    
    }
}
