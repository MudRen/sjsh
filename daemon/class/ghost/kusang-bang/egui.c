//谈笑退天兵  wosshipg
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
string msg,targetrude;
int my,him;
  int success,hurt,diff,damage;
   int myexp=(int)me->query("combat_exp")/5000+(int)me->query("daoxing")/5000;
  int mylev=(int)me->query_skill("stick")/2+ (int)me->query_skill("qianjun-bang");
  int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
  int targetlev, targetstr,targetkar,targetexp,targeteffkee;
  string *hitone = ({
HIY "$n眼睁睁的看着落下的棒子,一副绝望的表情。$n哼了一声已重重的吃了一棍.\n",
 HIY "$n眼前出现了无数饿鬼，挥舞手中的棒子一起扑来.$N趁$n分神的时候一个闷棍正中$n的脑袋.\n",
  });
  string *missone = ({
BLU "$n早有防备,将计就计的漏出一个破绽,待到$N打来之时,侧身退步,向$N肋间打出.$N蹙不急防,只好闪身躲避,这一招被$n尽数化解.\n",
BLU "$n哈哈大笑:雕虫小技,也来这里卖弄,不过是关公面前耍大刀!看我怎么收拾你!\n",
  });
  string *hittwo = ({
   HIW "$n看着$N,仿佛眼前是索命的阎王，面容恐怖，来势凶猛。$n顿时感到无形的压力，浑身发抖!\n",
  HIW "$n急忙将兵器架于头顶,$N将腕一抖,一招腋里偷桃，一棒打在$n的肋下.$n一个踉跄,差点摔倒!\n",
  });
  string *misstwo = ({
CYN "原来$n故作痴呆,诱惑$N,等到$N欺身靠近,$n大喝一声:拿命来!转而攻向$N!\n",
CYN "$n突然一个虎跳,竟然跳到$N背后,$N一脸茫然,不知道发生了什么事情!\n",
  });
  string *hitthree = ({
  HIR "$n万分恐惧的看着眼前的鬼影，不知道到底是发生了什么事情。突然影子中一个闪亮的光影扑面而来,$n被一棒打在面门!\n",
  });
  string *missthree = ({
HIG "说时迟,那时快.$n举起手中的兵器奋力一架,乒的一声,接住了$N劈下来的棒子!\n",
HIG "$n狂笑一声:你也太小瞧我了!\n",
  });
  string *hit=({
      HIW "$N厉声喝道：$n你的死期到了,跟我去见阎王。说着不容分说，上前就打！\n"NOR,
     HIW "这一招着实厉害,$n连反应都没有来得急就被$N重击一棒,肩膀裂开一道深深的口子，露出了白森森的骨头,伤势严重!\n"NOR,
  });
  string *miss;
  
  if( !target ) target = offensive_target(me);
  if( !target
     ||      !target->is_character()
     ||      !me->is_fighting(target) )
    return notify_fail("千均棒不是练着好看的，只能对战斗对手施用。\n");
  targetrude=RANK_D->query_self_rude(target);
  miss=({
 BLU"$n哈哈大笑道："+targetrude+"听说这千均棒有多少威力，现在一看，也不过如此嘛！\n"NOR,
    BLU"$n长笑一声，对$N不屑地说道：就这点本事，"+targetrude+"还没放在眼里！\n"NOR,
    BLU"$n仰天大笑道：还有什么本事，尽管拿出来吧！\n"NOR,
  });
     if((string)me->query_skill_mapped("force")!="tonsillit")
      return notify_fail("perfrom egui必须以gouhunshu为底子。\n");
        if(me->query_skill("gouhunshu",1) < 150)
      return notify_fail("你的gouhunshu不到150级，无法使用perform egui。\n");
     if(me->query_skill("kusang-bang",1)<150)
       return notify_fail("你对kusang-bang的理解不够，无法一气呵成地使出！\n");
  if(me->query("max_force") < 1000 || me->query("force")<500)
     return notify_fail("你的内力不足，难以使出这么精妙的招数。\n");
 targetexp=(int)target->query("combat_exp")/5000+(int)target->query("daoxing")/5000;
  targetlev=(int)target->query_skill("parry")/2+(int)target->query_skill("dodge");
targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
my=mystr+mylev+myexp;
him=targetstr+targetlev+targetexp;
   msg = CYN "$N一声暴喝：饿鬼临门！\n\n只见一道道黑影伴着磷火迎面扑出，手中的棒子直劈$n顶门！\n" NOR;
if( random(my) > him*3/4)
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=missone[random(sizeof(missone))];
    msg+=CYN"\n$N气势凶猛，分毫没有给对手留下还手的余地。招式狠毒无比！除了招架$n已不知所措\n"NOR;
 if( random(my+him) > him)
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
     if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
    msg+=CYN"\n$N身手敏捷，行踪诡秘，真的如黑暗中的鬼魂，伴着森森的杀气环绕在$n周围！\n"NOR;
    if(random(my+him)>(him/2))
    {
      msg+=hitthree[random(sizeof(hitthree))];
      success+=1;
     if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=missthree[random(sizeof(missthree))];
  diff=3-success;
  if (diff<0) diff = 0;
  if (success) hurt=damage*hurt/success;
  else hurt=0;
  me->add("force", -(150*success+70*diff));
  targeteffkee=(int)target->query("eff_kee");
  target->receive_wound("kee", targeteffkee*hurt/100);
  target->receive_damage("kee", target->query("kee")*(damage-hurt)/100);
  if(success)
    {
me->start_busy(1+random(4-(mystr)/50));
target->start_busy(3+random(4-(mystr)/50));
      msg+=hit[random(sizeof(hit))];
    }
  else
    {
me->start_busy(1+random(4-(mystr)/50));
      msg+=miss[random(sizeof(miss))];
    }
  message_vision(msg, me, target);
  return 1;
}
