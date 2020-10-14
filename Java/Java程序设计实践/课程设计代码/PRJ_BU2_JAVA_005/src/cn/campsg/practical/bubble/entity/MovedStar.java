package cn.campsg.practical.bubble.entity;

public class MovedStar extends Star
{
	private Position movedPosition;

	public MovedStar(Position position,StarType type,Position movedPosition)
	{
		Position p = new Position(position.getRow(),position.getColumn());
		setPosition(p);
		setType(type);
		this.movedPosition = movedPosition;
	}

	public MovedStar(){}
	
	@Override
	public String toString()
	{
		return getPosition().toString()+",type:"+getType().name()+"\nnew position£º("+movedPosition.getRow()+","+movedPosition.getColumn()+")";
	}
	public Position getMovedPosition()

    {

        return movedPosition;

    }



    public void setMovedPosition(Position movedPosition)

    {

        this.movedPosition = movedPosition;

    }



    public static void main(String[] args) {

        Position p1 = new Position(0,0);

        Position p2 = new Position(1,1);

        StarType c = StarType.RED;

        MovedStar ms = new MovedStar(p1,c,p2);

        System.out.print("position:("+p1.getColumn()+","+p1.getRow()+"),");
        System.out.println("type:"+c);
        System.out.println("new position:("+p2.getColumn()+","+p2.getRow()+")");

        //powered by Jingyu Zhang

    }

}

