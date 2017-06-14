package com.xatu.xiaoxu;
import java.util.*;
import java.io.*;
//演示java集合

class ClerkInfo
{
	private String empNo;
	private String name;
	//private int age;
	private float sal;	
	
	
	public String getEmpNo() {
		return empNo;
	}
	public void setEmpNo(String empNo) {
		this.empNo = empNo;
	}
	
	
	public String getName() {
		return name;
	}
	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public float getSal() {
		return sal;
	}

	public void setSal(float sal) {
		this.sal = sal;
	}

	public void setName(String name) {
		this.name = name;
	}

	
	public ClerkInfo(String _empNo,String _name,float _sal)
	{
		this.empNo = _empNo;
		this.sal = _sal;
		this.name = _name;
	}
	
	
}

//雇员管理类
class EmpManage
{
	private ArrayList al = null;
	public EmpManage()
	{
		al  = new ArrayList();
	}
	
	//加入员工
	public void addEmp(ClerkInfo emp)
	{
		al.add(emp);
	}
	
	public void showInfo(String empNo)
	{
		//遍历整个ArrayList
		for(int i = 0; i < al.size(); i++)
		{
			//取出对象
			ClerkInfo emp = (ClerkInfo)al.get(i);
			
			//比较编号
			if(emp.getEmpNo().equals(empNo))
			{
				
				System.out.println("找到该员工，他的信息是：");
				System.out.println("编号="+empNo);
				System.out.println("名字="+emp.getName());
				System.out.println("工资="+emp.getSal());
			}
		}
	}
	
	//修改工资
	public void updateSal(String empNo,float newSal)
	{
		for(int i = 0; i < al.size(); i++ )
		{
			ClerkInfo emp = (ClerkInfo)al.get(i);
			if(emp.getEmpNo().equals(empNo))
			{
				emp.setSal(newSal);
			}
		}
	}
	
	//删除员工
	public void delEmp(String empNo)
	{
		for(int i = 0; i < al.size(); i++)
		{
			ClerkInfo emp = (ClerkInfo)al.get(i);
			if(emp.getEmpNo().equals(empNo))
			{
				al.remove(i);
			}
		}
	}
	
}




public class Clerk {

	public static void main(String []args) throws Exception
	{

	
		EmpManage emp = new EmpManage();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//做出菜单
		while(true)
		{
			System.out.print("请选择>:\n");
			System.out.print("1: 添加雇员\n");
			System.out.print("2: 显示雇员\n");
			System.out.print("3: 修改工资\n");
			System.out.print("4: 删除员工\n");
			System.out.print("5: 退出系统\n");
			
			System.out.print("请输入你想选择的编号：>\n");
			String str = br.readLine();
			if(str.equals("1"))
			{
				System.out.print("请输入添加雇员的编号：>");
				String empNo = br.readLine();
				System.out.print("请输入添加雇员的姓名：>");
				String Name = br.readLine();
				System.out.print("请输入添加雇员的工资：>");
				float Salary = Float.parseFloat(br.readLine());
				
				ClerkInfo clk = new ClerkInfo(empNo,Name,Salary);
				emp.addEmp(clk);
				
			}
			else if(str.equals("2"))
			{
				System.out.print("请输入想要显示的雇员编号：>");
				String empNo = br.readLine();
				emp.showInfo(empNo);
			}
			else if(str.equals("3"))
			{
				System.out.print("请输入想要修改的雇员的编号：>");
				String empNo = br.readLine();
				System.out.print("请输入想要修改的雇员的工资：>");
				float newSal  = Float.parseFloat(br.readLine());
				
				emp.updateSal(empNo, newSal);
			}
			else if(str.equals("4"))
			{
				System.out.print("请输入想要删除的雇员的编号：>");
				String empNo = br.readLine();
				emp.delEmp(empNo);
			}
			else
			{
				System.exit(0);
				
			}
			
			
		}
	
	}
}

