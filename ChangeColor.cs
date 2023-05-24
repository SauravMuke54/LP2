using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeColor : MonoBehaviour
{
    [SerializeField]
    GameObject sp,cb;
    
    [SerializeField]
    Texture[] texture;
    
    Renderer cr,sr;
    
    Color c;
    
    float i1,i2,i3;

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
    
    	i1=Random.Range(0f,1f);
    	i2=Random.Range(0f,1f);
    	i3=Random.Range(0f,1f);
    	c=new Color(i1,i2,i3);
    	cr.material.SetColor("_Color",c);
    		sr.material.SetColor("_Color",c);
        
    }
}
