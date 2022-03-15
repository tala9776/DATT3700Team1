////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// Main Class /////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Timer;
import java.util.TimerTask;

class Main extends TimerTask {
    
  int colR;
  int colG;
  int colB;
  
  float moveX;
  float moveY;
  float moveZ;
  
  final int colSize = 5;
  final int rowSize = 5;
  final int size = colSize * rowSize; 
  
  Timer timer = new Timer();
  
  Branch[] list = new Branch[size];
  


  void create(){
     for (int i = 0; i < size; i++){
       list[i] = new Branch();
     }
  }
  
    void logic(){
      
  /* 
  
  updateRate 30/s
  transSpeed
  moveSpeed
  
  float randChance = rand(0,1);
  
  
  if randChance < 0.75                        =>    float randVal = rand(0,1)
  else                                        =>    randVal = 1
  
  
  if cubeColorIn == yes                       =>    branchCol = ((currentCol + cubeCol)/2) * randVal
  
  
  if 10 > pressure > 5                        =>    branchCol = <color orange> * randVal
                                                    branchLumin = (branchLumin + 0.2) * randVal
                                                    move(<away, less> * randVal)
                                                    
                                                    
  if pressure >10                             =>    branchCol = <color red> * randVal
                                                    branchLumin += 0.5
                                                    move(<away, more> * randVal)
  
 
  if pressure < 5                             
     if time > 3s                             =>    branchCol = cubeColorIn * randVal
     if time > 8s                             =>    branchCol = cubeColorIn * (randVal * 1.3)
                                              
  
  
  
  */  
  
    }
  

  
  public static void main(){
    create();
  }   
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// Cube Class /////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  class Input{
  
    private boolean[] sides = new boolean[5];
    private String[] sideNames = {"Top", "Left", "Front", "Right", "Back"};
    private boolean pressence;
    
    private boolean touch;
    private float sens;
    private float pressure;

    public Input(){
      this.touch = false;
      this.sens = 0;
      this.pressure = 0;
      this.pressence = false;
      
      for (int i = 0; i < 5; i++){
        this.sides[i] = false;
      }
      
    }
    
    void isPressent(){
      this.pressence = true;
    }
    
    void touch(boolean touch){
      this.touch = touch;
      }
  
    void touchSide(String s){
      touch(true);
      if (this.touch == true){
        switch (s){
          case "top":
            this.sides[0] = true;
            break;
          case "left":
            this.sides[1] = true;
            break;
          case "front":
            this.sides[2] = true;
            break;
          case "right":
            this.sides[3] = true;
            break;
          case "back":
            this.sides[4] = true;
            break;
        }  
      }
    }
    
    
    
    public String beingTouched(){
      String s = "None.";
        
      for (int i = 0; i < 5; i++){
        if (this.sides[i] == true){
          s = this.sideNames[i];
        }
      }
      
      return s;
    }
  
    void setSensitivity(float sens){
      this.sens = sens;
    }
    
    void setPressure(float pressure){
      this.pressure = pressure;
    }    
    
    public float getSensitivity(){
      return this.sens;
    }
    
    public float getPressure(){
      return this.pressure;
    }
  
  
  }
  
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// Branch Class ///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Branch{
  
  int colR;
  int colG;
  int colB;
  int brightness;  
  int[] col = new int[4];
  
  int moveX;
  int moveY;
  int moveZ;
  int movSpeed;
  
    public Branch(){
      this.col[0] = 0;
      this.col[1] = 0;
      this.col[2] = 0;
      this.col[3] = 0;
      
      this.moveX = 0;
      this.moveY = 0;
      this.moveZ = 0;
      this.movSpeed = 0;
    }
    
    public void setColor(int red, int green, int blue,int lumin){
      this.col[0] = red;
      this.col[1] = green;
      this.col[2] = blue;
      this.col[3] = lumin;
    }
    
    public int[] getColor(){
      return this.col;
    }
    
    public void move(int moveX, int moveY, int moveZ, int movSpeed){
      this.moveX = moveX;
      this.moveY = moveY;
      this.moveZ = moveZ;
      this.movSpeed = movSpeed;
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
