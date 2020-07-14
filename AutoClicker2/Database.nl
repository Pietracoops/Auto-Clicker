*the input should follow this type of format
*Code | Value | Duration Before Click (milliseconds) | X Coordinate | Y Coordinate | Menu Click  | Trigger |
*Explanation of Each Column - NOTE: DO NOT USE TAB

*Use $ before a code to force click it. When a value is "Forced"
*it is added into the clicking sequence, as dictated by the rubric.nl document
*


*Code: This is the identifier inside the input.nl -> for example "POPT(23)"
*Value: For certain inputs, a value is required. If no input, type "Void". If user defined value, enter "Value"
*Duration After Click: This is a value in seconds for the wait time after the click is executed. Useful for when windows need to load
*X Coordinate: X pixel coordinate
*Y Coordinate: Y pixel Coordinate
*Menu Click: Will make sure that the menu click is performed before the option click. Enter "Void" if no menu required)
*Trigger: These are the codes that this parameter is dependant on. It is the "If" condition. For example: if POPT(23) = 1,
*POPT(24) becomes visible in GUI. if we define the click for POPT(24), "POPT(23) = 1" will be its trigger. You can have up to 45 Triggers.


*Code   (0)          | Value (1)    |Duration(2)    |   X (3) |   Y (4) |       Menu Click (5)   |   Trigger  (6)    | Trigger2  (7) |

*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% RASTO GUI %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

AircraftModel        | Void         |      1500     |    53   |   167   |     Void               |    Void           |
ACTYPE               | CS100        |      4000     |    53   |   191   |     AircraftModel      |    Void           | 
ACTYPE               | CS300        |      4000     |    53   |   206   |     AircraftModel      |    Void           |

Engine               | Void         |      1500     |    53   |   210   |     Void               |    Void           |
ENGTYP               | PW1524G      |      4000     |    53   |   240   |     Engine             |    Void           |
ENGTYP               | PW1521G      |      4000     |    53   |   252   |     Engine             |    Void           |
ENGTYP               | PW1519G      |      4000     |    53   |   266   |     Engine             |    Void           |
  
$Calculator          | Void         |      1500     |    171  |    65   |     Void               |    Void           |

*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% AIRCRAFT DATA TAB %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Tab Click 
$AircraftData        | Void         |      1500     |    104  |   104   |     Void               |     Void          |

*Maximum Weight Allowed
MaxWeightAllowed     | Void         |      1500     |    357  |   102   |     Void               |    Void           |
POPT(23)             |    0         |      1500     |    357  |   120   |     MaxWeightAllowed   |    Void           |
POPT(23)             |    1         |      1500     |    357  |   135   |     MaxWeightAllowed   |    Void           |

POPT(24)             | Value        |      1500     |    357  |   145   |     Void               |    POPT(23)=1     |                                                                                                                 

ForwardCG            | Void         |      1500     |    363  |   145   |     Void               |    POPT(23)=0     |
ForwardCG            | Void         |      1500     |    363  |   180   |     Void               |    POPT(23)=1     |
POPT(30)             |    0         |      1500     |    363  |   163   |     ForwardCG          |    POPT(23)=0     |
POPT(30)             |    1         |      1500     |    363  |   178   |     ForwardCG          |    POPT(23)=0     |
POPT(30)             |    0         |      1500     |    363  |   198   |     ForwardCG          |    POPT(23)=1     |
POPT(30)             |    1         |      1500     |    363  |   211   |     ForwardCG          |    POPT(23)=1     |

TakeoffFlap          | Void         |      1500     |    363  |   188   |     Void               |    POPT(23)=0     |
TakeoffFlap          | Void         |      1500     |    363  |   224   |     Void               |    POPT(23)=1     |
CONF(3)              |    1         |      1500     |    363  |   204   |     TakeoffFlap        |    POPT(23)=0     |
CONF(3)              |    1         |      1500     |    363  |   240   |     TakeoffFlap        |    POPT(23)=1     |                                                                                                                    
CONF(3)              |    2         |      1500     |    363  |   218   |     TakeoffFlap        |    POPT(23)=0     |
CONF(3)              |    2         |      1500     |    363  |   255   |     TakeoffFlap        |    POPT(23)=1     |  
CONF(3)              |    3         |      1500     |    363  |   232   |     TakeoffFlap        |    POPT(23)=0     |
CONF(3)              |    3         |      1500     |    363  |   268   |     TakeoffFlap        |    POPT(23)=1     |   


ApproachLand         | Void         |      1500     |    363  |   231   |     Void               |    POPT(23)=0     |
ApproachLand         | Void         |      1500     |    363  |   265   |     Void               |    POPT(23)=1     |
CONF(36)             |    1         |      1500     |    363  |   245   |     ApproachLand       |    POPT(23)=0     |
CONF(36)             |    1         |      1500     |    363  |   282   |     ApproachLand       |    POPT(23)=1     |                                                                                                                    
CONF(36)             |    2         |      1500     |    363  |   260   |     ApproachLand       |    POPT(23)=0     |
CONF(36)             |    2         |      1500     |    363  |   298   |     ApproachLand       |    POPT(23)=1     | 


END                                                                         

