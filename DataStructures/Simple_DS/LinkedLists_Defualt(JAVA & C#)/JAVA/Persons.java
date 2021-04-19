package Liists;
//کلاس مربوط به اشخاص
public class Persons
{
	//کلاس اشخاص برای گرفتن ویژگی های هر فردconstructor
	public Persons(String name, String family, String id)
	{
		setPrpName(name);
		setPrpFamily(family);
		setPrpID(id);
	}
	//ست کردن ویژگی های افراد
	private String prpName;
	public final String getPrpName()
	{
		return prpName;
	}
	public final void setPrpName(String value)
	{
		prpName = value;
	}
	private String prpFamily;
	public final String getPrpFamily()
	{
		return prpFamily;
	}
	public final void setPrpFamily(String value)
	{
		prpFamily = value;
	}
	private String prpID;
	public final String getPrpID()
	{
		return prpID;
	}
	public final void setPrpID(String value)
	{
		prpID = value;
	}

}