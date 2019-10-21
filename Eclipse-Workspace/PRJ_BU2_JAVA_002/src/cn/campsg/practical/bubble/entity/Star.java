package cn.campsg.practical.bubble.entity;

public class Star
{
    public Position position;
    StarType type;
    public enum StarType
    {
    	BLUE(0),GREEN(1),YELLOW(2),RED(3),PURPLE(4);
        int value;
        String color;
        StarType(int value)
        {
            this.value = value;
        }
        StarType(int value, String color)
        {
            this.value = value;
            this.color = color;
        }
        StarType(){}

        public String getColor()
        {
            return color;
        }

        public void setColor(String color)
        {
            this.color = color;
        }

        public int getValue()
        {
            return value;
        }

        public void setValue(int value)
        {
            this.value = value;
        }

        public int value(String color)
        {
            return value;
        }


        public int value()
        {
            return value;
        }

        public static StarType valueOf(int num)
        {
        	
			if(num==0) {
				return BLUE;
			}
			else if(num==1) {
				return GREEN;
			}
			else if(num==2) {
				return YELLOW;
			}
			else if(num==3) {
				return RED;
			}
			else {return PURPLE;}
        }
        public static int StarNum (String color)
        {
        	
			if(color=="BLUE") {
				return 0;
			}
			else if(color=="GREEN") {
				return 1;
			}
			else if(color=="YELLOW") {
				return 2;
			}
			else if(color=="RED") {
				return 3;
			}
			else {return 4;}
        }
    }

    public StarType getType()
    {
        return type;
    }

    public void setType(StarType type)
    {
        this.type = type;
    }

    public Position getPosition()
    {
        return position;
    }

    public void setPosition(Position position)
    {
        this.position = position;
    }

    public Star(Position position, StarType type)
    {
        this.position = position;
        this.type = type;
    }

    public Star()
    {
        position = new Position();
    }
}

	//powered by Jingyu Zhang