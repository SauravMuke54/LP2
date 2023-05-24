using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeTexture : MonoBehaviour
{
    [SerializeField]
    GameObject sp,cb;
    
    [SerializeField]
    Texture[] texture;
    
    Renderer cr,sr;
    
    int index;

    // Start is called before the first frame update
    void Start()
    {
    	cr=cb.GetComponent<Renderer>();
    	sr=sp.GetComponent<Renderer>();
    	GetComponent<Button>().onClick.AddListener(changeTexture);
        
    }

    // Update is called once per frame
    void changeTexture()
    {
    
    	index=Random.Range(0,texture.Length);
    	cr.material.mainTexture=texture[index];
    	sr.material.mainTexture=texture[index];
        
    }
}
