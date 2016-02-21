// ս������� v.90 
// By Arron@xajh2 4/99
// file: detect.c
// Email: szarron@163.net
// http: szarron.163.net

#include <armor.h>
#include <combat.h>
#include <ansi.h>

inherit HEAD;

string* type = ({
"armor/head",
"armor/neck",
"armor/waist",
"armor/wrists",
"armor/finger",
"armor/hands",
"armor/boots",
//"shield",
});

string* people = ({
"   ��",//head
"��",//neck
"���Щ�",//waist
"��",//wrists
"��",//finger
"��",//hands
"��  ��",//boots
});

string* w_color = ({
"��>"+HIR"��"NOR,//head
HIM"��"NOR,//neck
HIC"���Щ�"NOR,//waist
HIB"��"NOR,//wrists
HIY"��"NOR +" <-",//finger
HIY"��"NOR,//hands
HIC"��  ��"NOR +" <-",//boots
});

string* wear = ({
"1",
"2",
"3",
"4",
"5",
"6",
"7",
});

string* w = ({
"1",
"2",
"3",
"4",
"5",
"6",
"7",
});

int do_detect(string arg);

void init()
{
        add_action("do_detect","detect");
}

void create()
{
        set_name("ս�������", ({ "fighting detect","detect" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ս�����������\n");
                set("material", "steel");
                set("armor_prop/armor", 1);
        }
        setup();
}

int do_detect(string arg)
{
        object me,ob;
//        string *wear, *w;
        string skill_type,line, w1,w2,w3;
        string c1,c2,c3,c4,c5;
        object weapon, we;
        int attack_points, dodge_points, parry_points;

        me = this_player();

        if( !arg ) return notify_fail("��Ҫ���ʲô��\n");

        if (arg == "?") {
                write("ս��������÷���\n");
                write("\t̽��Է���ʵ����detect <id>\n");
                write("\t̽��ĳ�����Ƿ���ս�������ˣ�detect <����>\n");
                return 1;
                }

        if( !query("equipped") )
                return notify_fail("Ҫװ���ϲ���ʹ�á�\n");

        if(!wizardp(me) && arg == me->query("id"))
                return notify_fail("���Ѿ��������������������Լ���\n");

        if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
        else {

        for (int i=0;i<sizeof(type);i++) {
                if (we = ob->query_temp(type[i])) {
                 wear[i]= we ->query("name");
                 wear[i] += HIC"(������"NOR + BLINK + HIR;
                wear[i] += sprintf("%d",we->query("armor_prop/armor"));
                 wear[i] += NOR + HIC")"NOR;
                 w[i]=w_color[i];
                } else {
                 wear[i] = NOR;
                 w[i]=people[i];
                 }
        }

        c1="����"+w[1]+"�Щ�";
        c2="��  ��";
        c3=w[2];
        c4="���ة�";
        c5="��  ��";

        if( ob->query_temp("armor/cloth") ){
                c1=HIW"����"NOR+w[1]+HIW"�Щ�"NOR;
                c1 += "<-" + ob->query_temp("armor/cloth")->query("name");
                c1 += HIC"(������"NOR + BLINK + HIR +
                ob->query_temp("armor/cloth")->query("armor_prop/armor")+ NOR + HIC")"NOR;
                c2=HIW + c2 +NOR;
                c3=HIW+ w[2]+NOR;
                c4=HIW + c4 +NOR;
                c5=HIW + c5 +NOR;
        }

        c2 = w[3] +c2 +w[3];
        c3 = w[5] +c3 +w[5];
        
        if( objectp(weapon = ob->query_temp("weapon")) ) {
                skill_type = weapon->query("skill_type");
                w1 =YEL"��"NOR;
                w2 =YEL"��"NOR;
                w3 =YEL"��"NOR;
        }else{
                w1 ="��";
                w2 ="  ";
                w3 ="  ";
		skill_type = "unarmed";
        }

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

        message_vision(CYN"�����٣���"NOR"$N����$n������ս���������\n", me, ob);

        line = "����һ�ᣬҺ��������ʾ����\n";
        line += ob->query("name") + "ս���������\n\n";
        line += "\t " + wear[0] +"\n";
        line += "\t "+ w[0] + wear[1]+"\n";
        line += "\t" + c1 + "\n";
        line += "\t" + c2 + wear[3] + "\n";
        line += "\t" + c3 + wear[5] + "\n";
        line += "\t"+w1 + c4 +w[4]+wear[4]+"\n";
        line += "\t"+w2+c5 +"\n";
        line += "\t"+w3+c5+"\n";
        line += "\t  " + w[6] +wear[6]+"\n";
        line += "\n\t������ߣ�";

        if( ob->query_temp("armor/0") ){
                line += ob->query_temp("armor/0")->query("name");
                line += HIC"(������"NOR + BLINK + HIR +
                ob->query_temp("armor/0")->query("armor_prop/armor")+ NOR + HIC")\n"NOR;
                } else
                line += "��\n";
        
        line +="\tս��������";

        if( w2 !="  " ){
                line += weapon->query("name");
                line += HIC"(��������"NOR + BLINK + HIR +
                weapon->query("weapon_prop/damage")+ NOR + HIC")\n"NOR;
                } else
                line += "��\n";

        if( ob->query_temp("apply/attack")) {
                line += "\tǱ�ڹ�������(";
                line += sprintf("%d",ob->query_temp("apply/attack")) +")\n";
                }

        if( ob->query_temp("apply/damage")){
                line += "\tǱ���ƻ�����(";
                line += sprintf("%d",ob->query_temp("apply/damage")) +")\n";
                }

        if( ob->query_temp("apply/defense")){
                line += "\tǱ�ڷ�������(";
                line += sprintf("%d",ob->query_temp("apply/defense")) +")\n";
                }

        if(ob->query_temp("apply/dodge")){
                line += "\tǱ������ֵ��(";
                line +=ob->query_temp("apply/dodge") +")\n";
                }
                
        if(ob->query_temp("apply/armor")){
                line += "\tǱ�ڷ�������(";
                line +=ob->query_temp("apply/armor") +")\n";
                }

        write(line);

        write(sprintf("\n\tս����������" HIW "%d (+%d)" NOR "\n\tս����������" HIW "%d (+%d)\n\n" NOR,
		attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor")));

                }
        
        return 1;
}