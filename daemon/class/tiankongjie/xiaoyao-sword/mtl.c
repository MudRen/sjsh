//lost
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
  string msg,targetrude;
  int success,hurt,diff,damage;
  int myexp=(int)me->query("combat_exp")/3000;
  int mylev=(int)me->query_skill("unarmed");
  int mystr=(int)me->query("str")+(int)(me->query_skill("sword")/10-2);
  int mykar=(int)me->query_kar();
  int targetlev, targetstr,targetkar,targetexp,targeteffkee;
  string *hitone = ({
    "$n�ۼ���������ǵ�Ϯ����ȴ��֪��ζ�ܣ����һ���������������\n",
    "$n����ת����ͼ������⣬��Ϊʱ���������Ӽ�ͷ������\n",
    "$n���������Ŵ��ˣ��޴Ӷ�����һ���������û���С����\n",
  });
  string *missone = ({
    "$n����һ�������������˿�ȥ����Ȼ�����������ͣ���û�˵�$n�ֺ���\n",
    "$n�߾����б��з���һ����ֻ��һ��ƹ⣬$N�����Ľ�����Ӳ��������\n",
    "$n���ӽ�������ͣ������������ֿ������������ڿ�������������һ��ǿ�⡣\n",
  });
  string *hittwo = ({
    "$n˿��û�������⿴��ƽ����һ����ȴ�������б仯�쳣�����$n���ϳ������صĻ��ˣ�\n",
    "$nû���$N�������֮�죬��æ��ͷ���ܣ����޷��㿪������������Ƥ��������\n",
    "����$N����̫�죬$n�ط����������ϱ����һƬƤ����Ȼ�˵ò��ᣡ\n",
  });
  string *misstwo = ({
    "$n����΢΢һ�࣬�ܹ���$N�Ŀ콣��\n",
    "$n�ƺ������ϵ���һ�У�˳�ƽ�$N��������һ�ƣ����˿�ȥ��\n",
    "�ۿ�����Ҫ��$n�Դ������Դ���ͻȻ��$n�����ڱ���֮�ϣ�����һ�����Ƶ�$Nֻ�û����Ծȡ�\n",
  });
  string *hitthree = ({
    "$nһʱ�ۻ���$N����һ�ƣ���͸��$n���Ļ�Ѩ��$n�³�һ����Ѫ��\n",
    "$n����$N���Ʒ���·��һ�ѽ�$N������ץס������$N����Ϊ���棬�������û���$n�����ţ�\n",
    "$n��ͼ�ñ����ÿ�$N�����أ�ȴ��$N������ͼ��ת����ý�������$n���ĺ�Ѩ��\n",
  });
  string *missthree = ({
    "$n�ƺ�������֪���е���·��������ת֮�£���$N�����������ƽ⡣\n",
    "$n����$N�Ľ�����·��һ�ѽ�$N������ץס���������������Ρ�\n",
    "$n��������Σ�գ��й�ֱ����������$N�İٻ�Ѩ����Ȼ�����л����ˡ�\n",
  });
  string *hit=({
    HIC"$N�˹�����������Ҳ��֮��ɢ��\n"NOR,
    HIC"����ս����٢�޽����Ȼ��ͬ���죬$n�������ģ��Ѿ�վ��ס�ˡ�\n"NOR,
    HIC"$N������Ц��������ô�������֪�������˰ɣ�������\n"NOR,
  });
  string *miss;
  
        if( (string)me->query("family/family_name") != "��ս�")
     return notify_fail("�㲻����ս���ˣ���ʹ�������С�\n");
  if( !target ) target = offensive_target(me);
  if( !target
     ||      !target->is_character()
     ||      !me->is_fighting(target) )
    return notify_fail("ֻ�ܶ�ս������ʩչ����٢�޽��󡱡�\n");
  targetexp=(int)target->query("combat_exp")/5000;
  targetlev=(int)target->query_skill("parry");
  targetstr=(int)target->query("str")+(int)(target->query_skill("dodge")/10-2);
  targetkar=(int)target->query_kar();
  miss=({
    HIM"$n������Ц������������ս����٢�޽����ô���������쿴����Ҳ������ˣ���\n"NOR,
    HIM"$nһ���Ц����Ҫʤ�ң��ٵ�ʮ��ɣ���\n"NOR,
    HIM"$n�����Ц���������С��������ҳݣ���\n"NOR,
  });
  if((string)me->query_skill_mapped("force")!="mtl-force")
    return notify_fail("��ʽ��٢�޽���������٢���ľ��ĺ�����������\n");
  if(me->query_skill("mtl-force",1) < 250)
    return notify_fail("����ڹ����Ӳ��㣬�޷�������ɢ�����⡣\n");
  if(me->query_skill("xiaoyao-sword",1)<250)
    return notify_fail("�����ң��������Ϥ���޷��˽����磡\n");
  if(me->query_skill("piaoyun-zhang",1)<250)
    return notify_fail("���Ʈ���Ʋ�����Ϥ���޷���׼Ѩλ��\n");
  if(me->query("max_force") < 2000 || me->query("force")<1500)
    return notify_fail("����������㣬���������������ˡ�\n");
  msg = HIC "$N���һ��������٢���ľ���ɲ�Ǽ��캮֮��ɢ���������γ��������
"HIW"������$N���˺�һ��$n�����ȥ��\n" NOR;
  if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage=15+random(mykar/3);
    }
  else msg+=missone[random(sizeof(missone))];
  msg+=HIW"\n$N���֮��˳������бб�������д̳�һ����\n"NOR;
  if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
  msg+=HIW"\n$N�˹�������������$n��ͬʱ���¼�����ת��һ�����˹�ȥ��\n"NOR;
  if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
    {
      msg+=hitthree[random(sizeof(hitthree))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=missthree[random(sizeof(missthree))];
  diff=3-success;
  if (diff<0) diff = 0;
  if (success) hurt=damage*hurt/success;
  else hurt=0;
  me->add("force", -(400*success+200*diff));
  targeteffkee=(int)target->query("eff_kee");
  target->receive_wound("kee", targeteffkee*hurt/50);
  target->receive_damage("kee", target->query("kee")*(damage-hurt)/50);

  if(success)
    {
    me->start_busy(2+random(4-(mykar+5)/10));
  msg+=hit[random(sizeof(hit))];  
  message_vision(msg, me, target);
  COMBAT_D->report_status(target);        

    }
  else
    {
        me->start_busy(1+random(4-(mykar+5)/10));
      msg+=miss[random(sizeof(miss))];
  message_vision(msg, me, target);
    }       
  return 1;
}


