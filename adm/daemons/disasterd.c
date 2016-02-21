// /feature/disaster.c
// �ƽ�ϵͳ��������
// ��ע������!����������֮�ݺ�������(202.103.98.74-5555)
// �� ���� ��С����(xhm)������ƽ(tianping)  

#include <ansi.h>
inherit F_DBASE;
void copy_npc(int count);
string query_site();
void verdict_time(int t,int count);
void juedou();

string *factions=({"����ɽ","���ƶ�","��ɽ����","��ׯ��","��ѩɽ","�Ϻ�����ɽ","�¹�","���޵ظ�","��������","�ݿ�ɽ�޵׶�","����ɽ��˿��","����ɽ���Ƕ�","������",});
string faction;     //��Ź��������
int Cnpcend, count;
object lead;
void create()
{
    seteuid(getuid());
    set("name", "��ؽ�");
    set("id", "disaster");
  remove_call_out("disaster");
  call_out("disaster",30,0);   
}

//�ƽ�ϵͳ������������
void disaster(int count)
{
	if(count==0){
        message("system",HIR"����ؽ١�"HIW"̫�׽��ǣ����������̫���ˣ���ʹ��ħ������\n"NOR,users());
	message("system", HIR"����ؽ١�"HIW"̫�׽��ǣ�������ؼ�һ���ƽ��������⣡\n"NOR,users());
	}	
	faction = factions[count];
        message("system",HIR"����ؽ١�"HIW"ħ�̵ĵ�"+chinese_number(count+1)+"��Ŀ����Ѫϴ��"HIR+faction+HIW"����\n"NOR,users());
//	message("system", HIR"����ؽ١�"HIW"���ڴ�е�ǰ�������ڿ�ʼ�������״̬���κ��˲����������ӣ�\n"NOR,users());
	call_out("copy_npc",11,count);
//	copy_npc();
}

//����EXP and SKILL��ָ�������ȵ�ɱ��(pker)
void copy_npc(int count)
{
	object ob, *user;
	string site,leader;
	int i, j, exp, skill;
	int t=0;

	user = users();
	j = sizeof(user);
	Cnpcend = 0;
	for (i=0;i<j;i++) {
		if (user[i]->query("family/family_name")!=faction
		||user[i]->query("combat_exp")<30000||wizardp(user[i]))
			continue;
                  if (!user[i]||wizardp(user[i])) continue;
               switch(faction){
                case "�Ϻ�����ɽ":
  	              ob = new("/d/haojie/yg-putuo");
  	              leader="��������";
  	              break;
                case "��ׯ��":
  	              ob = new("/d/haojie/yg-wzg");
  	              leader="��Ԫ����";
  	              break;
                case "��ѩɽ":
  	              ob = new("/d/haojie/yg-xueshan");
  	              leader="��������";
  	              break;
                case "���޵ظ�":
  	              ob = new("/d/haojie/yg-hell");
  	              leader="�ز�������";
  	              break;
                case "��������":
  	              ob = new("/d/haojie/yg-dragon");
  	              leader="��������";
  	              break;
                case "�ݿ�ɽ�޵׶�":
  	              ob = new("/d/haojie/yg-wudidong");
  	              leader="����";
  	              break;
                case "��ɽ����":
  	              ob = new("/d/haojie/yg-shushan");
  	              leader="��ɽ��ʥ";
  	              break;
                case "����ɽ��˿��":
  	              ob = new("/d/haojie/yg-pansi");
  	              leader="��ϼ����";
  	              break;
                case "����ɽ���Ƕ�":
  	              ob = new("/d/haojie/yg-fangcun");
  	              leader="������ʦ";
  	              break;
                case "���ƶ�":
  	              ob = new("/d/haojie/yg-hyd");
  	              leader="�캢��";
  	              break;
                case "������":
  	              ob = new("/d/haojie/yg-jjf");
  	              leader="����";
  	              break;
                case "�¹�":
  	              ob = new("/d/haojie/yg-moon");
  	              leader="�϶�����";
  	              break;
  	        case "����ɽ":      
                       ob = new("/d/haojie/yg-sanjie");
                       leader="������ʦ";
                       break;      
  	              }
		site = query_site();
//                  ob->set("title",HIR"��ħСͷĿ"NOR);
		ob->copy_status(ob,user[i]);
		ob->move(site);
                tell_object(user[i], HIY""+leader+"������:ħ�����Ʊ���,�ٻر�����ս��\n");
		message_vision("$N�����ɷ�����˹�����\n",ob);
                t++;
	}

	if (t==0) {
		if (count < 12) {
			message("system", HIR"����ؽ١�"HIW"����"+faction+"���¿���һ�ˣ�ħ�̲�ս��ʤ��һ��������"+faction+"��\n"NOR,users());
			message("system", HIR"����ؽ١�"HIW"ħ�̽�����ħ�����Ц����û�뵽������׵��֣�����������Ҳ����������������һ����\n"NOR,users());
			call_out("disaster",11,count+1);
		}
		else {
		message("system", HIR"����ؽ١�"HIW"��Ȼ���ɷ���ɱ�У�����ħ�̣�������ʧ̫��һʱ���ȷ�Ѫ�꣬����һƬ�찵��\n"NOR,users());
		message("system", HIR"����ؽ١�"HIW"̫�׽��ǣ�ħ����Ȼ��ʱ���ˣ�����֪ʲôʱ���ֻ��������!\n"NOR,users());
			call_out("disaster",3600,0);
                   call_out("juedou",5);
		}
	}
	else {
		Cnpcend = 1;
		call_out("verdict_time",1000,t,count);
	}
}

//���������������pker����ŵص�
string query_site()
{
	mapping sites=([
                "������":		({"/d/jjf/gate","/d/jjf/stone_road","/d/jjf/pavillion"}),
	        "���ƶ�":		({"/d/qujing/kusong/songlin1","/d/qujing/kusong/kusongjian","/d/qujing/kusong/yongdao1"}),
	     "�Ϻ�����ɽ":	({"/d/nanhai/gate","/d/nanhai/tingjing","/d/nanhai/guangchang"}),
	        "��ׯ��":		({"/d/qujing/wuzhuang/linyin2","/d/qujing/wuzhuang/guangchang"}),
	        "��ѩɽ":		({"/d/xueshan/shanpo","/d/xueshan/xuelu"}),
	          "�¹�":	({"/d/moon/backyard","/d/moon/neartop","/d/moon/road3"}),
	       "���޵ظ�":	({"/d/death/gate","/d/death/new-walk2"}),
	       "��������":	({"/d/sea/gate","/d/sea/yujie2","/d/sea/under4"}),
	    "�ݿ�ɽ�޵׶�":	({"/d/qujing/wudidong/dong","/d/qujing/wudidong/dong2"}),
	       "��ɽ����":	({"/d/shushan/square","/d/shushan/shanjiao"}),
	    "����ɽ��˿��":	({"/d/pansi/damen","/d/pansi/hubian"}),
	     "����ɽ���Ƕ�":	({"/d/lingtai/uphill5","/d/lingtai/gate1"}),
	         "����ɽ":	        ({"/d/sanjie/tianyidian4","/d/sanjie/tianyaodian","/d/sanjie/tianyidian4"}),
	]);

	return sites[faction][random(sizeof(sites[faction]))];
}

void juedou()
{
	object ob;
	object *user;
	int i, exp, skill, killer = 0;

	user = users();
	for(i=0;i<sizeof(user);i++)
		if (user[i]->query_temp("hj_killer") > killer) lead = user[i];

        ob = new("/d/haojie/zhanshu.c");
	ob->move(lead);
	message_vision(HIY"һ��ս��Ʈ����$N����ǰ��\n"NOR,lead);
	message("system", HIM"����ؽ١�"+"��˵"+lead->name()+HIM"�õ���һ��ħ�̽��������������ս�顣\n"NOR,users());

	exp = lead->query("combat_exp");
	skill = lead->query_skill("parry",1);
        ob = new("/d/haojie/mengmo.c");
	ob->set("pk_target",lead);
	ob->move("/d/city/center.c");
	message_vision("$N�����ɷ�����˹�����\n",ob);
}

//��ʱ�жϺƽٷ�����ʱ���Ƿ񳬹����ޣ������������ҳͷ�
void verdict_time(int t,int count)
{
	object *user;
	int i,exp;
        if(DISASTER_D->query("xinmo_die")<t){
	user = users();
		for(i=0;i<sizeof(user);i++) {
			if (!user[i]||user[i]->query("family/family_name") != faction)continue;
			exp = (int) user[i]->query("daoxing") * 0.01;
			if (exp > 1000) exp=1000;
			user[i]->add("daoxing",-exp);
		    tell_object(user[i], HIC"ħ��Ѫϴ"+faction+"����,�㻤��������ʧȥ��"+COMBAT_D->chinese_daoxing(exp)+"���У�\n");
		}
	message("system", HIR"����ؽ١�"HIW+faction+"������ս֮�£��������أ��Ӵ������伣��\n"NOR,users());
	}else{
	message("system", HIR"����ؽ١�"HIW+faction+"������ս֮�£�������ħ�̣��������ⳡ�ƽ١�\n"NOR,users());
	}
	DISASTER_D->delete("xinmo_die");
	if (count<12  ) {
		message("system", HIR"����ؽ١�"HIW"ħ�̽�����ħ�������һ������һ����\n"NOR,users());
		call_out("disaster",11,count+1);
	}
	else {
		message("system", HIR"����ؽ١�"HIW"��Ȼ���ɷ���ɱ�У�����ħ�̣�������ʧ̫��һʱ���ȷ�Ѫ�꣬����һƬ�찵��\n"NOR,users());
		message("system", HIR"����ؽ١�"HIW"̫�׽��ǣ�ħ����Ȼ��ʱ���ˣ�����֪ʲôʱ���ֻ��������!\n"NOR,users());
		call_out("disaster",3600,0);
		call_out("juedou",5);
	}
}
