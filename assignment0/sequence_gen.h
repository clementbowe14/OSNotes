void createUniformlyDistributedList(int list[], int size, int min, int max);
void createNormallyDistributedList(double list[], int size, double mu, double sigma);
void createNormallyRandomDistributedList(double list[], int size, double mu, double sigma, double min, double max);
void createDivideRandomDistAndNormalDist(double resultList[], double normalDist[], double normalTrunc[], int size);
void createSpecialDistributionSequence(double resultList[], int uniform[], double normalDist[], double normalTrunc[], int size);
void initializeRandomSeed();

