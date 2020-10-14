package cn.campsg.practical.bubble.entity;

public class Position
{
    private Position position;
    private int row,column;
    

    public Position getPosition()
    {
        return position;
    }

    public void setPosition(Position position)
    {
        this.position = position;
    }

    public int getRow()
    {
        return row;
    }

    public void setRow(int row)
    {
        this.row = row;
    }
    
    public int getColumn()
    {
        return column;
    }

    public void setColumn(int column)
    {
        this.column = column;
    }
    
    public Position(){}

    public Position(int row,int column)
    {
        this.row = row;
        this.column = column;
    }

	public String getConlumn() {
		return null;
	}
}
	//powered by Jingyu Zhang
