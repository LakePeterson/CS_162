struct county
{
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
};

struct state
{
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* counties;
  int n_counties;
};

void intro();

void menuStates();

struct state* allocate_states(int);

void read_state_data(struct state* states, int, std::ifstream&);

struct county* allocate_counties(int);

void read_county_data(struct county* counties, int, std::ifstream&);

void menuChoice(state*, int, int);

bool stateHighMedIncome(const state &, const state &);

bool stateLowMedIncome(const state &, const state &);

bool stateHighUnemployment(const state &, const state &);

bool stateLowUnemployment(const state &, const state &);

bool stateCompare(const state &, const state &);

bool stateCompareMedSal(const state &a, const state &b);

bool countyHighMedIncome(const county &, const county &);

bool countyLowMedIncome(const county &, const county &);

bool countyHighUnemployment(const county &, const county &);

bool countyLowUnemployment(const county &, const county &);

bool countyCompare(const county &, const county &);

bool countyCompareMedSal(const county &a, const county &b);

void stateInfo(int);

void free_state_data(struct state*);
