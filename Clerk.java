package com.xatu.xiaoxu;
import java.util.*;
import java.io.*;
//��ʾjava����

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

//��Ա������
class EmpManage
{
	private ArrayList al = null;
	public EmpManage()
	{
		al  = new ArrayList();
	}
	
	//����Ա��
	public void addEmp(ClerkInfo emp)
	{
		al.add(emp);
	}
	
	public void showInfo(String empNo)
	{
		//��������ArrayList
		for(int i = 0; i < al.size(); i++)
		{
			//ȡ������
			ClerkInfo emp = (ClerkInfo)al.get(i);
			
			//�Ƚϱ��
			if(emp.getEmpNo().equals(empNo))
			{
				
				System.out.println("�ҵ���Ա����������Ϣ�ǣ�");
				System.out.println("���="+empNo);
				System.out.println("����="+emp.getName());
				System.out.println("����="+emp.getSal());
			}
		}
	}
	
	//�޸Ĺ���
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
	
	//ɾ��Ա��
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
		
		//�����˵�
		while(true)
		{
			System.out.print("��ѡ��>:\n");
			System.out.print("1: ��ӹ�Ա\n");
			System.out.print("2: ��ʾ��Ա\n");
			System.out.print("3: �޸Ĺ���\n");
			System.out.print("4: ɾ��Ա��\n");
			System.out.print("5: �˳�ϵͳ\n");
			
			System.out.print("����������ѡ��ı�ţ�>\n");
			String str = br.readLine();
			if(str.equals("1"))
			{
				System.out.print("��������ӹ�Ա�ı�ţ�>");
				String empNo = br.readLine();
				System.out.print("��������ӹ�Ա��������>");
				String Name = br.readLine();
				System.out.print("��������ӹ�Ա�Ĺ��ʣ�>");
				float Salary = Float.parseFloat(br.readLine());
				
				ClerkInfo clk = new ClerkInfo(empNo,Name,Salary);
				emp.addEmp(clk);
				
			}
			else if(str.equals("2"))
			{
				System.out.print("��������Ҫ��ʾ�Ĺ�Ա��ţ�>");
				String empNo = br.readLine();
				emp.showInfo(empNo);
			}
			else if(str.equals("3"))
			{
				System.out.print("��������Ҫ�޸ĵĹ�Ա�ı�ţ�>");
				String empNo = br.readLine();
				System.out.print("��������Ҫ�޸ĵĹ�Ա�Ĺ��ʣ�>");
				float newSal  = Float.parseFloat(br.readLine());
				
				emp.updateSal(empNo, newSal);
			}
			else if(str.equals("4"))
			{
				System.out.print("��������Ҫɾ���Ĺ�Ա�ı�ţ�>");
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

