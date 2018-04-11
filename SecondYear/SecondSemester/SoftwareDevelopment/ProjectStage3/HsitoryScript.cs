using System.Deployment.Internal;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class HsitoryScript : MonoBehaviour {

    [Header("Text Vars")] 
    public Text[] names = new Text[11];
    
    public Text[] type = new Text[11];
    
    public Text[] score = new Text[11];
    
    public Text[] date = new Text[11];
    
    public Image BgImage;

    public Sprite Default, city, mountain, lion;

    private void Awake() {
        int historyEntries = PlayerPrefs.GetInt("historyNumber", 0);

        HistoryEntryClass[] historyData = new HistoryEntryClass[historyEntries];

        string path;
        string loadedData;
        
        for (int i = 0; i < historyEntries; i++) {
            path = Application.streamingAssetsPath + "/HistoryEvents/HistoryEvent" + i + ".json";

            loadedData = File.ReadAllText(path);
            historyData[i] = JsonUtility.FromJson<HistoryEntryClass>(loadedData);
            
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

        for (int i = 0; i < historyEntries; i++) {
            for (int j = 0; j < historyEntries; j++) {
                names[i].text = historyData[i].User;
            }
            for (int j = 0; j < historyEntries; j++) {
                type[i].text = historyData[i].EventType;
            }
            for (int j = 0; j < historyEntries; j++) {
                score[i].text = historyData[i].Score;
            }
            for (int j = 0; j < historyEntries; j++) {
                date[i].text = historyData[i].Time;
            }
            
        }
}

    public void MainMenuButtonFunc() {
        SceneManager.LoadScene("_Scene_MainMenu");
    }

    public void ClearHistoryButtonFunc() {
        int historyEntries = PlayerPrefs.GetInt("historyNumber", 0);

        string path;
        
        for (int i = 0; i < historyEntries; i++) {
            path = Application.streamingAssetsPath + "/HistoryEvents/HistoryEvent" + i + ".json";

            File.Delete(path);
            PlayerPrefs.SetInt("historyNumber", -1);
            SceneManager.LoadScene("_Scene_History");
        }
    }
    
}
