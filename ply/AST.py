
class Node(object):
    def __str__(self):
        return self.printTree()

class Program(Node):
    def __init__(self, declarations, fundefs, instructions):
        self.declarations=declarations
        self.fundefs=fundefs
        self.instructions=instructions

class Decl(Node):
    def __init__(self):
        self.list=[]

class Init(Node):
    def __init__(self,id,expression):
        self.id=id
        self.expression=expression

class ParExpr(Node):
    def __init__(self,expression):
        self.expression=expression

class BinExpr(Node):
    def __init__(self,first,operator,second):
        self.first=first
        self.operator=operator
        self.second=second

class FunExpr(Node):
    def __init__(self,id,expressionList):
        self.id=id
        self.expressionList=expressionList

class FunDef(Node):
    def __init__(self,type,id,argList,compoundInstr):
        self.type=type
        self.id=id
        self.argList=argList
        self.compoundInstr=compoundInstr

class Arg(Node):
    def __init__(self,type,id):
        self.type=type
        self.id=id

class CompoundInstr(Node):
    def __init__(self,declarations,instructions):
        self.declarations=declarations
        self.instructions=instructions
        
class PrintInstr(Node):
    def __init__(self,expression):
        self.expression=expression
        
class LabeledInstr(Node):
    def __init__(self,id,instruction):
        self.id=id
        self.instruction=instruction
        
class Assignment(Node):
    def __init__(self,id,expression):
        self.id=id
        self.expression=expression

class ChoiceInstr(Node):
    def __init__(self,condition,instruction,elseInstruction):
        self.condition=condition
        self.instruction=instruction
        self.elseInstruction=elseInstruction       
        
class WhileInstr(Node):
    def __init__(self,condition,instruction):
        self.condition=condition
        self.instruction=instruction
        
class RepeatInstr(Node):
    def __init__(self,instructions,condition):
        self.instructions=instructions
        self.condition=condition

class ReturnInstr(Node):
    def __init__(self,expression):
        self.expression=expression

# ...


